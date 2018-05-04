#include "blockcipherwindow.h"
#include "ui_blockcipherwindow.h"

BlockCipherWindow::BlockCipherWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockCipherWindow)
{
    ui->setupUi(this);
}

BlockCipherWindow::~BlockCipherWindow()
{
    delete ui;
}

void BlockCipherWindow::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}
