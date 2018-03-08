#ifndef RSA_WIDGET_H
#define RSA_WIDGET_H

#include <QMainWindow>
#include "librsa/rsa.h"

namespace Ui {
class RSA_widget;
}

class RSA_widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit RSA_widget(QWidget *parent = 0);
    ~RSA_widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RSA_widget *ui;
};

#endif // RSA_WIDGET_H
