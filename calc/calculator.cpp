#include "calculator.h"
#include "ui_calculator.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;


calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
    ui -> Display -> setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i =0; i<10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i],SIGNAL(released()),this,SLOT(NumPressed()));
    }

    connect(ui->Add,SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->Subtract,SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->Multiply,SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->Divide,SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->Equals,SIGNAL(released()),this,SLOT(EqualButtonPressed()));
    connect(ui->ChangeSign,SIGNAL(released()),this,SLOT(ChangeSign()));
    connect(ui->Clear,SIGNAL(released()),this,SLOT(Clear()));
}







calculator::~calculator()
{
    delete ui;
}

void calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui ->Display->text();
    if((displayVal.toDouble()==0)|| (displayVal.toDouble()==0.0)){
        ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal,'g',16));
    }
}

void calculator::MathButtonPressed(){

     divTrigger = false;
     multTrigger = false;
     addTrigger = false;
     subTrigger = false;

     QString displayVal = ui->Display->text();
     calcVal = displayVal.toDouble();

     QPushButton *button = (QPushButton *)sender();
     QString butVal = button->text();
     if (QString::compare(butVal,"/",Qt::CaseSensitive)==0){
         divTrigger = true;
     } else if (QString::compare(butVal,"*",Qt::CaseSensitive)==0){
         multTrigger = true;
     } else if (QString::compare(butVal,"+",Qt::CaseSensitive)==0){
         addTrigger = true;
     } else if (QString::compare(butVal,"-",Qt::CaseSensitive)==0){
         subTrigger = true;
     }
     ui->Display->setText("");
}

void calculator::EqualButtonPressed(){

    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    if(addTrigger||subTrigger||multTrigger||divTrigger){

        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        } else if(subTrigger){
            solution = calcVal - dblDisplayVal;
        }else if(multTrigger){
            solution = calcVal * dblDisplayVal;
        }else if(divTrigger){
            solution = calcVal / dblDisplayVal;
        }

    }
    ui->Display->setText(QString::number(solution));

}

void calculator::ChangeSign(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    solution = -1.0 * dblDisplayVal;
    ui->Display->setText(QString::number(solution));

}

void calculator::Clear(){

    ui->Display->setText(QString::number(0.0));


}
