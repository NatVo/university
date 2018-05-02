#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <blockcipher.h>
#include <rsawindow.h>

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
    void on_ButtonVernam_clicked();

    void on_ButtonRSA_clicked();
    void on_ButtonSequence_clicked();
    void on_ButtonBlockCipher_clicked();

private:
    Ui::MainWindow *ui;

    RSAWindow *rsaWindow;
    BlockCipher *blockcipherWindow;
};

#endif // MAINWINDOW_H
