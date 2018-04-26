#include "rsawindow.h"
#include "ui_rsawindow.h"

RSAWindow::RSAWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RSAWindow)
{
    ui->setupUi(this);
}

RSAWindow::~RSAWindow()
{
    delete ui;
}
