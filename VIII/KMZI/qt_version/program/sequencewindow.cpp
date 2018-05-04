#include "sequencewindow.h"
#include "ui_sequencewindow.h"

SequenceWindow::SequenceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceWindow)
{
    ui->setupUi(this);
}

SequenceWindow::~SequenceWindow()
{
    delete ui;
}

void SequenceWindow::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}
