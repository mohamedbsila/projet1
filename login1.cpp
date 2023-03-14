#include "login1.h"
#include "ui_login1.h"
#include "mainwindow.h"


login1::login1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login1)
{
    ui->setupUi(this);
}

login1::~login1()
{
    delete ui;
}

void login1::on_pushButton_clicked()
{

}
