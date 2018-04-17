#include "sequence.h"
#include "ui_sequence.h"

Sequence::Sequence(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sequence)
{
    ui->setupUi(this);
}

Sequence::~Sequence()
{
    delete ui;
}

void Sequence::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}
