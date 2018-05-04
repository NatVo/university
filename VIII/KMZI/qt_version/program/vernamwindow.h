#ifndef VERNAMWINDOW_H
#define VERNAMWINDOW_H

#include <QWidget>

namespace Ui {
class VernamWindow;
}

class VernamWindow : public QWidget
{
    Q_OBJECT

signals:
    void startWindow();

public:
    explicit VernamWindow(QWidget *parent = 0);
    ~VernamWindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::VernamWindow *ui;
};

#endif // VERNAMWINDOW_H
