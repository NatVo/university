#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <blockcipherwindow.h>
#include <rsawindow.h>

#include <sequence.h>

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
    BlockcipherWindow *blockcipherWindow;
    Sequence *sequenceWindow;
};

#endif // MAINWINDOW_H
