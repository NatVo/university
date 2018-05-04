#include "vernamwindow.h"
#include "ui_vernamwindow.h"

VernamWindow::VernamWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VernamWindow)
{
    ui->setupUi(this);
}

VernamWindow::~VernamWindow()
{
    delete ui;
}

void VernamWindow::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}
