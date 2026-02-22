#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QCoreApplication>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    head = nullptr;
    last = nullptr;

    loadJsonToLinkedList();  // Load existing students
    displayStudents();        // Display history
}

MainWindow::~MainWindow()
{
    Node* temp = head;
    while(temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    delete ui;
}

// ADD STUDENT
void MainWindow::on_addButton_clicked()
{
    QString rollStr = ui->rollInput->text();
    QString name = ui->nameInput->text();
    QString gpaStr = ui->gpaInput->text();

    if (rollStr.isEmpty() || name.isEmpty() || gpaStr.isEmpty()) {
        ui->textEdit->setText("All fields are required.");
        return;
    }

    int roll = rollStr.toInt();
    double gpa = gpaStr.toDouble();

    if (gpa < 0 || gpa > 4.0) {
        ui->textEdit->setText("GPA must be between 0 and 4.0");
        return;
    }

    Node* tempCheck = head;
    while(tempCheck) {
        if(tempCheck->roll == roll) {
            ui->textEdit->setText("Roll number already exists.");
            return;
        }
        tempCheck = tempCheck->next;
    }

    Node* newNode = new Node{roll, name, gpa, nullptr};

    if(!head) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }

    saveLinkedListToJson();
    displayStudents();

    ui->textEdit->setText("Student Added ✅");
    ui->rollInput->clear();
    ui->nameInput->clear();
    ui->gpaInput->clear();
}

// DELETE STUDENT
void MainWindow::on_deleteButton_clicked()
{
    QString selectedRollStr = ui->rollSelector->currentText();
    if(selectedRollStr.isEmpty()) {
        ui->textEdit->setText("No roll selected.");
        return;
    }

    int selectedRoll = selectedRollStr.toInt();

    // Remove from linked list
    Node* temp = head;
    Node* prev = nullptr;
    bool found = false;
    while(temp) {
        if(temp->roll == selectedRoll) {
            found = true;
            if(prev) prev->next = temp->next;
            else head = temp->next;
            if(temp == last) last = prev;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if(!found) {
        ui->textEdit->setText("Roll not found.");
        return;
    }

    saveLinkedListToJson();
    displayStudents();

    ui->textEdit->setText("Student Deleted ✅");
}

//SAVE LINKED LIST TO JSON
void MainWindow::saveLinkedListToJson()
{
    QJsonArray studentsArray;
    Node* temp = head;
    while(temp) {
        QJsonObject student;
        student["roll"] = temp->roll;
        student["name"] = temp->name;
        student["gpa"] = temp->gpa;
        studentsArray.append(student);
        temp = temp->next;
    }

    QString path = QCoreApplication::applicationDirPath() + "/students.json";
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) return;

    QJsonDocument doc(studentsArray);
    file.write(doc.toJson());
    file.close();
}

// LOAD JSON TO LINKED LIST
void MainWindow::loadJsonToLinkedList()
{
    QString path = QCoreApplication::applicationDirPath() + "/students.json";
    QFile file(path);
    if(!file.exists()) return;
    if(!file.open(QIODevice::ReadOnly)) return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if(doc.isNull() || !doc.isArray()) return;

    // Clear existing list
    Node* temp = head;
    while(temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
    last = nullptr;

    QJsonArray studentsArray = doc.array();
    for(const auto &s : studentsArray) {
        QJsonObject obj = s.toObject();
        Node* newNode = new Node{
            obj["roll"].toInt(),
            obj["name"].toString(),
            obj["gpa"].toDouble(),
            nullptr
        };
        if(!head) { head = newNode; last = newNode; }
        else { last->next = newNode; last = newNode; }
    }
}

//  DISPLAY STUDENTS IN HISTORY
void MainWindow::displayStudents()
{
    QVector<QJsonObject> students;

    Node* temp = head;
    while(temp) {
        QJsonObject obj;
        obj["roll"] = temp->roll;
        obj["name"] = temp->name;
        obj["gpa"] = temp->gpa;
        students.append(obj);
        temp = temp->next;
    }

    std::sort(students.begin(), students.end(),
              [](QJsonObject a, QJsonObject b) {
                  return a["roll"].toInt() < b["roll"].toInt();
              });

    QString output;
    for(const auto &s : students) {
        output += "Roll: " + QString::number(s["roll"].toInt()) + "\n";
        output += "Name: " + s["name"].toString() + "\n";
        output += "GPA: " + QString::number(s["gpa"].toDouble()) + "\n";
        output += "----------------------------------\n";
    }

    ui->history->setText(output);
    loadRollNumbers();  // Refresh roll numbers in delete dropdown
}

//    LOAD ROLL NUMBERS
void MainWindow::loadRollNumbers()
{
    ui->rollSelector->clear();

    Node* temp = head;
    QVector<int> rolls;
    while(temp) {
        rolls.append(temp->roll);
        temp = temp->next;
    }

    std::sort(rolls.begin(), rolls.end());

    for(int r : rolls)
        ui->rollSelector->addItem(QString::number(r));
}
