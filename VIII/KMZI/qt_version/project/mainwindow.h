#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <blockcipher.h>
<<<<<<< HEAD
#include <rsawindow.h>
=======
#include <rsa.h>
#include <sequence.h>
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005

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
    Sequence *sequenceWindow;
};

#endif // MAINWINDOW_H
