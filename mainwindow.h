#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Linked list node structure
struct Node {
    int roll;
    QString name;
    double gpa;
    Node* next;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();  // Delete selected roll
    void displayStudents();
    void loadRollNumbers();

private:
    Ui::MainWindow *ui;
    Node* head;
    Node* last;

    void saveLinkedListToJson();
    void loadJsonToLinkedList();
};

#endif // MAINWINDOW_H
