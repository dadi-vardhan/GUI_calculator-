#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = 0);
    ~calculator();

private:
    Ui::calculator *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeSign();
    void Clear();
    double add(double x,double y);
    double subtract(double x,double y);
    double multiply(double x,double y);
    double divide(double x,double y);

};
#endif // CALCULATOR_H
