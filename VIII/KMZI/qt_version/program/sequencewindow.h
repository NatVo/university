#ifndef SEQUENCEWINDOW_H
#define SEQUENCEWINDOW_H

#include <QWidget>

namespace Ui {
class SequenceWindow;
}

class SequenceWindow : public QWidget
{
    Q_OBJECT

signals:
    void startWindow();

public:
    explicit SequenceWindow(QWidget *parent = 0);
    ~SequenceWindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::SequenceWindow *ui;
};

#endif // SEQUENCEWINDOW_H
