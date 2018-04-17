#ifndef RSA_H
#define RSA_H

#include <QWidget>

namespace Ui {
class RSA;
}

class RSA : public QWidget
{
    Q_OBJECT

signals:
    void startWindow();

public:
    explicit RSA(QWidget *parent = 0);
    ~RSA();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::RSA *ui;
};

#endif // RSA_H
