#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //RSA
    rsaWindow = new RSA();
    connect(rsaWindow, &RSA::startWindow, this, &MainWindow::show);

    //Block Cipher
    blockcipherWindow = new BlockCipher();
    connect(blockcipherWindow, &BlockCipher::startWindow, this, &MainWindow::show);

    //Sequence
    sequenceWindow = new Sequence();
    connect(sequenceWindow , &Sequence::startWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonVernam_clicked()
{

}

void MainWindow::on_ButtonBlockCipher_clicked()
{
    rsaWindow->show();
    this->close();
}

void MainWindow::on_ButtonRSA_clicked()
{
    blockcipherWindow->show();
    this->close();
}


void MainWindow::on_ButtonSequence_clicked()
{
    sequenceWindow->show();
    this->close();

}

