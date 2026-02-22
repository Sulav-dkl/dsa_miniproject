/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addButton;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *history;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QComboBox *rollSelector;
    QPushButton *deleteButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *rollInput;
    QLineEdit *nameInput;
    QLineEdit *gpaInput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(140, 210, 81, 21));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(280, 100, 104, 64));
        textEdit->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 61, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 130, 41, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 170, 37, 12));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 10, 591, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(24);
        font.setBold(true);
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(660, 0, 141, 101));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        label_5->setScaledContents(true);
        history = new QTextEdit(centralwidget);
        history->setObjectName("history");
        history->setGeometry(QRect(133, 300, 311, 231));
        history->setReadOnly(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(490, 310, 82, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rollSelector = new QComboBox(widget);
        rollSelector->setObjectName("rollSelector");

        verticalLayout->addWidget(rollSelector);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setStyleSheet(QString::fromUtf8("  QPushButton {\n"
"          background-color: rgb(255, 5, 9);\n"
"          color: white;\n"
"          border-radius: 10px;\n"
"          font-weight: bold;\n"
"          padding: 6px;\n"
"      }\n"
"      QPushButton:hover {\n"
"          background-color: rgb(170, 0, 0);\n"
"      }\n"
"      QPushButton:pressed {\n"
"          background-color: #1c5980;\n"
"      }\n"
"     "));

        verticalLayout->addWidget(deleteButton);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(130, 90, 120, 100));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        rollInput = new QLineEdit(widget1);
        rollInput->setObjectName("rollInput");
        rollInput->setStyleSheet(QString::fromUtf8("\n"
"      QLineEdit {\n"
"          border: 2px solid #3498db;\n"
"          border-radius: 8px;\n"
"          background-color: #ecf0f1;\n"
"          padding: 4px;\n"
"          font-size: 12pt;\n"
"			color: black\n"
"      }\n"
"      QLineEdit:focus {\n"
"          border: 2px solid #e74c3c;\n"
"      }\n"
"     "));

        verticalLayout_2->addWidget(rollInput);

        nameInput = new QLineEdit(widget1);
        nameInput->setObjectName("nameInput");
        nameInput->setStyleSheet(QString::fromUtf8("\n"
"      QLineEdit {\n"
"          border: 2px solid #3498db;\n"
"          border-radius: 8px;\n"
"          background-color: #ecf0f1;\n"
"          padding: 4px;\n"
"          font-size: 12pt;\n"
"			color: black;\n"
"      }\n"
"      QLineEdit:focus {\n"
"          border: 2px solid #e74c3c;\n"
"      }\n"
"     "));

        verticalLayout_2->addWidget(nameInput);

        gpaInput = new QLineEdit(widget1);
        gpaInput->setObjectName("gpaInput");
        gpaInput->setStyleSheet(QString::fromUtf8("\n"
"      QLineEdit {\n"
"          border: 2px solid #3498db;\n"
"          border-radius: 8px;\n"
"          background-color: white;\n"
"          padding: 4px;\n"
"          font-size: 12pt;\n"
"			color:black;\n"
"      }\n"
"      QLineEdit:focus {\n"
"          border: 2px solid #e74c3c;\n"
"      }\n"
"     "));

        verticalLayout_2->addWidget(gpaInput);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(gpaInput, addButton);
        QWidget::setTabOrder(addButton, textEdit);
        QWidget::setTabOrder(textEdit, rollInput);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"    QMainWindow {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #a8edea, stop:1 #fed6e3);\n"
"    }\n"
"   ", nullptr));
        addButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"      QPushButton {\n"
"          background-color: #3498db;\n"
"          color: white;\n"
"          border-radius: 10px;\n"
"          font-weight: bold;\n"
"          padding: 6px;\n"
"      }\n"
"      QPushButton:hover {\n"
"          background-color: #2980b9;\n"
"      }\n"
"      QPushButton:pressed {\n"
"          background-color: #1c5980;\n"
"      }\n"
"     ", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        label->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { color: #2c3e50; font-weight: bold; font-size: 10pt; }", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ROLLNO:", nullptr));
        label_2->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { color: #2c3e50; font-weight: bold; font-size: 10pt; }", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "NAME:", nullptr));
        label_3->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { color: #2c3e50; font-weight: bold; font-size: 10pt; }", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "GPA:", nullptr));
        label_4->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { color: #2c3e50; font-weight: bold; }", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "STUDENT MANAGEMENT SYSTEM", nullptr));
        label_5->setText(QString());
        deleteButton->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
