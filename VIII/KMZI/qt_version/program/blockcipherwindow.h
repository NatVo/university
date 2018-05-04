#ifndef BLOCKCIPHERWINDOW_H
#define BLOCKCIPHERWINDOW_H

#include <QWidget>

namespace Ui {
class BlockCipherWindow;
}

class BlockCipherWindow : public QWidget
{
    Q_OBJECT

signals:
    void startWindow();

public:
    explicit BlockCipherWindow(QWidget *parent = 0);
    ~BlockCipherWindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::BlockCipherWindow *ui;
};

#endif // BLOCKCIPHERWINDOW_H
