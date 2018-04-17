#include "blockcipher.h"
#include "ui_blockcipher.h"

BlockCipher::BlockCipher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockCipher)
{
    ui->setupUi(this);
}

BlockCipher::~BlockCipher()
{
    delete ui;
}

void BlockCipher::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}
