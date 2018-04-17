#ifndef BLOCKCIPHER_H
#define BLOCKCIPHER_H

#include <QWidget>

namespace Ui {
class BlockCipher;
}

class BlockCipher : public QWidget
{
    Q_OBJECT

public:
    explicit BlockCipher(QWidget *parent = 0);
    ~BlockCipher();

signals:
    void startWindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::BlockCipher *ui;
};

#endif // BLOCKCIPHER_H
