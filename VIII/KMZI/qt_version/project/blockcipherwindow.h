#ifndef BLOCKCIPHERWINDOW_H
#define BLOCKCIPHERWINDOW_H

#include <QWidget>

namespace Ui {
class BlockcipherWindow;
}

class BlockcipherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BlockcipherWindow(QWidget *parent = 0);
    ~BlockcipherWindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::BlockcipherWindow *ui;
};

#endif // BLOCKCIPHERWINDOW_H
