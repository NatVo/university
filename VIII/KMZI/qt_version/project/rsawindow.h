#ifndef RSAWINDOW_H
#define RSAWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QString>

#include "lib/rsa.h"

namespace Ui {
class RSAWindow;
}

class RSAWindow : public QWidget
{
    Q_OBJECT

signals:
    void startWindow();

public:
    explicit RSAWindow(QWidget *parent = 0);
    ~RSAWindow();

private slots:
    void on_ButtonBack_clicked();

    void on_pushButton_clicked();

private:
    Ui::RSAWindow *ui;
};

#endif // RSAWINDOW_H
