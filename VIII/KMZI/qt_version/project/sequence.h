#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QWidget>

namespace Ui {
class Sequence;
}

class Sequence : public QWidget
{
    Q_OBJECT

signals:
    void startWindow();

public:
    explicit Sequence(QWidget *parent = 0);
    ~Sequence();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::Sequence *ui;
};

#endif // SEQUENCE_H
