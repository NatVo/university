#include "rsawindow.h"
#include "ui_rsawindow.h"

#include "lib/rsa.h"
#include "lib/rsa.cpp"

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

void RSAWindow::on_ButtonBack_clicked()
{
    this->close();
    emit startWindow();
}

void RSAWindow::on_pushButton_clicked()
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
