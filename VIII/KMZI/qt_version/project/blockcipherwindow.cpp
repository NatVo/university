#include "blockcipherwindow.h"
#include "ui_blockcipherwindow.h"

BlockcipherWindow::BlockcipherWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockcipherWindow)
{
    ui->setupUi(this);
}

BlockcipherWindow::~BlockcipherWindow()
{
    delete ui;
}

void BlockcipherWindow::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}
