#include "rsa_widget.h"
#include "ui_rsa_widget.h"

#include "librsa/rsa.h"
#include "librsa/rsa.cpp"

#include <QDebug>
#include <QString>

RSA_widget::RSA_widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RSA_widget)
{
    ui->setupUi(this);
}

RSA_widget::~RSA_widget()
{
    delete ui;
}

void RSA_widget::on_pushButton_clicked()
{
    bool valid1;
    bool valid2;

    int p1 = ui->primeNumber1->text().toInt(&valid1);
    int p2 = ui->primeNumber2->text().toInt(&valid2);

    QString message = ui->textInput->toPlainText();
    ui->error->setText("");

    if (message != NULL)
    {
        if (valid1 && valid2)
        {
            RSA<std::string> line(message.toUtf8().constData(), p1, p2);
        }
        else
        {
            ui->error->setText("<font color='red'>Некорректный ввод данных!</font>");
        }

    }
    else
    {
        ui->error->setText("<font color='red'>Введите сообщение!</font>");
    }


}
