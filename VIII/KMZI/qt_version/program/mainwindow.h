#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vernamwindow.h>
#include <rsawindow.h>
#include <sequencewindow.h>
#include <blockcipherwindow.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_VernamButton_clicked();

    void on_RSAButton_clicked();

    void on_BlockCipherButton_clicked();

    void on_SequenceButton_clicked();

private:
    Ui::MainWindow *ui;
    VernamWindow *vernamWindow;
    RSAWindow *rsaWindow;
    SequenceWindow *sequenceWindow;
    BlockCipherWindow *blockcipherWindow;
};

#endif // MAINWINDOW_H
