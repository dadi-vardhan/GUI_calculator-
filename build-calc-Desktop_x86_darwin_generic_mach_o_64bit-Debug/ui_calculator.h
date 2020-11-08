/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculator
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *Button7;
    QPushButton *Button1;
    QPushButton *ChangeSign;
    QPushButton *Subtract;
    QPushButton *Button6;
    QPushButton *Divide;
    QPushButton *Button8;
    QLineEdit *Display;
    QPushButton *Add;
    QPushButton *Button4;
    QPushButton *Button0;
    QPushButton *Multiply;
    QPushButton *Button2;
    QPushButton *Button9;
    QPushButton *Button3;
    QPushButton *Clear;
    QPushButton *Button5;
    QPushButton *Equals;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calculator)
    {
        if (calculator->objectName().isEmpty())
            calculator->setObjectName(QString::fromUtf8("calculator"));
        calculator->resize(459, 314);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calculator->sizePolicy().hasHeightForWidth());
        calculator->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Button7 = new QPushButton(centralwidget);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        sizePolicy.setHeightForWidth(Button7->sizePolicy().hasHeightForWidth());
        Button7->setSizePolicy(sizePolicy);
        Button7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button7, 1, 0, 1, 1);

        Button1 = new QPushButton(centralwidget);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        sizePolicy.setHeightForWidth(Button1->sizePolicy().hasHeightForWidth());
        Button1->setSizePolicy(sizePolicy);
        Button1->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button1, 3, 0, 1, 1);

        ChangeSign = new QPushButton(centralwidget);
        ChangeSign->setObjectName(QString::fromUtf8("ChangeSign"));
        sizePolicy.setHeightForWidth(ChangeSign->sizePolicy().hasHeightForWidth());
        ChangeSign->setSizePolicy(sizePolicy);
        ChangeSign->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(ChangeSign, 4, 2, 1, 1);

        Subtract = new QPushButton(centralwidget);
        Subtract->setObjectName(QString::fromUtf8("Subtract"));
        sizePolicy.setHeightForWidth(Subtract->sizePolicy().hasHeightForWidth());
        Subtract->setSizePolicy(sizePolicy);
        Subtract->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #FF8C00;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Subtract, 4, 3, 1, 1);

        Button6 = new QPushButton(centralwidget);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        sizePolicy.setHeightForWidth(Button6->sizePolicy().hasHeightForWidth());
        Button6->setSizePolicy(sizePolicy);
        Button6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button6, 2, 2, 1, 1);

        Divide = new QPushButton(centralwidget);
        Divide->setObjectName(QString::fromUtf8("Divide"));
        sizePolicy.setHeightForWidth(Divide->sizePolicy().hasHeightForWidth());
        Divide->setSizePolicy(sizePolicy);
        Divide->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #FF8C00;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Divide, 1, 3, 1, 1);

        Button8 = new QPushButton(centralwidget);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        sizePolicy.setHeightForWidth(Button8->sizePolicy().hasHeightForWidth());
        Button8->setSizePolicy(sizePolicy);
        Button8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button8, 1, 1, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        sizePolicy.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        Display->setFont(font);
        Display->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"  background-color: gray;\n"
"  border: 1px solid gray;\n"
"  color: #ffffff;\n"
"}"));
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(Display, 0, 0, 1, 5);

        Add = new QPushButton(centralwidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        sizePolicy.setHeightForWidth(Add->sizePolicy().hasHeightForWidth());
        Add->setSizePolicy(sizePolicy);
        Add->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #FF8C00;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Add, 3, 3, 1, 1);

        Button4 = new QPushButton(centralwidget);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        sizePolicy.setHeightForWidth(Button4->sizePolicy().hasHeightForWidth());
        Button4->setSizePolicy(sizePolicy);
        Button4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button4, 2, 0, 1, 1);

        Button0 = new QPushButton(centralwidget);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        sizePolicy.setHeightForWidth(Button0->sizePolicy().hasHeightForWidth());
        Button0->setSizePolicy(sizePolicy);
        Button0->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button0, 4, 1, 1, 1);

        Multiply = new QPushButton(centralwidget);
        Multiply->setObjectName(QString::fromUtf8("Multiply"));
        sizePolicy.setHeightForWidth(Multiply->sizePolicy().hasHeightForWidth());
        Multiply->setSizePolicy(sizePolicy);
        Multiply->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #FF8C00;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Multiply, 2, 3, 1, 1);

        Button2 = new QPushButton(centralwidget);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        sizePolicy.setHeightForWidth(Button2->sizePolicy().hasHeightForWidth());
        Button2->setSizePolicy(sizePolicy);
        Button2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button2, 3, 1, 1, 1);

        Button9 = new QPushButton(centralwidget);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        sizePolicy.setHeightForWidth(Button9->sizePolicy().hasHeightForWidth());
        Button9->setSizePolicy(sizePolicy);
        Button9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button9, 1, 2, 1, 1);

        Button3 = new QPushButton(centralwidget);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        sizePolicy.setHeightForWidth(Button3->sizePolicy().hasHeightForWidth());
        Button3->setSizePolicy(sizePolicy);
        Button3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button3, 3, 2, 1, 1);

        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        sizePolicy.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy);
        Clear->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Clear, 4, 0, 1, 1);

        Button5 = new QPushButton(centralwidget);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        sizePolicy.setHeightForWidth(Button5->sizePolicy().hasHeightForWidth());
        Button5->setSizePolicy(sizePolicy);
        Button5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #C0C0C0;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Button5, 2, 1, 1, 1);

        Equals = new QPushButton(centralwidget);
        Equals->setObjectName(QString::fromUtf8("Equals"));
        sizePolicy.setHeightForWidth(Equals->sizePolicy().hasHeightForWidth());
        Equals->setSizePolicy(sizePolicy);
        Equals->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  background-color: #FF8C00;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"  background-color: #A9A9A9;\n"
"  border: 1px solid gray;\n"
"  padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(Equals, 1, 4, 4, 1);

        calculator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(calculator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 459, 22));
        calculator->setMenuBar(menubar);
        statusbar = new QStatusBar(calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        calculator->setStatusBar(statusbar);

        retranslateUi(calculator);

        QMetaObject::connectSlotsByName(calculator);
    } // setupUi

    void retranslateUi(QMainWindow *calculator)
    {
        calculator->setWindowTitle(QCoreApplication::translate("calculator", "calculator", nullptr));
        Button7->setText(QCoreApplication::translate("calculator", "7", nullptr));
        Button1->setText(QCoreApplication::translate("calculator", "1", nullptr));
        ChangeSign->setText(QCoreApplication::translate("calculator", "+/-", nullptr));
        Subtract->setText(QCoreApplication::translate("calculator", "-", nullptr));
        Button6->setText(QCoreApplication::translate("calculator", "6", nullptr));
        Divide->setText(QCoreApplication::translate("calculator", "/", nullptr));
        Button8->setText(QCoreApplication::translate("calculator", "8", nullptr));
        Display->setText(QCoreApplication::translate("calculator", "0.0", nullptr));
        Add->setText(QCoreApplication::translate("calculator", "+", nullptr));
        Button4->setText(QCoreApplication::translate("calculator", "4", nullptr));
        Button0->setText(QCoreApplication::translate("calculator", "0", nullptr));
        Multiply->setText(QCoreApplication::translate("calculator", "*", nullptr));
        Button2->setText(QCoreApplication::translate("calculator", "2", nullptr));
        Button9->setText(QCoreApplication::translate("calculator", "9", nullptr));
        Button3->setText(QCoreApplication::translate("calculator", "3", nullptr));
        Clear->setText(QCoreApplication::translate("calculator", "AC", nullptr));
        Button5->setText(QCoreApplication::translate("calculator", "5", nullptr));
        Equals->setText(QCoreApplication::translate("calculator", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculator: public Ui_calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
