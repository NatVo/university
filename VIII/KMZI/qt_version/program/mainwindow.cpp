#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Vernam
    vernamWindow = new VernamWindow();
    connect(vernamWindow, &VernamWindow::startWindow, this, &MainWindow::show);

    //RSA
    rsaWindow = new RSAWindow();
    connect(rsaWindow, &RSAWindow::startWindow, this, &MainWindow::show);

    //Block Cipher
    blockcipherWindow = new BlockCipherWindow();
    connect(blockcipherWindow, &BlockCipherWindow::startWindow, this, &MainWindow::show);

    //Sequence
    sequenceWindow = new SequenceWindow();
    connect(sequenceWindow , &SequenceWindow::startWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_VernamButton_clicked()
{
    vernamWindow->show();
    this->close();
}

void MainWindow::on_RSAButton_clicked()
{
    rsaWindow->show();
    this->close();
}

void MainWindow::on_BlockCipherButton_clicked()
{
    blockcipherWindow->show();
    this->close();
}

void MainWindow::on_SequenceButton_clicked()
{
    sequenceWindow->show();
    this->close();
}
