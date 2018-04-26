#ifndef RSAWINDOW_H
#define RSAWINDOW_H

#include <QWidget>

namespace Ui {
class RSAWindow;
}

class RSAWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RSAWindow(QWidget *parent = 0);
    ~RSAWindow();

private:
    Ui::RSAWindow *ui;
};

#endif // RSAWINDOW_H
