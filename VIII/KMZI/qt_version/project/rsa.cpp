#include "rsa.h"
#include "ui_rsa.h"

RSA::RSA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RSA)
{
    ui->setupUi(this);
}

RSA::~RSA()
{
    delete ui;
}

void RSA::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}
