/********************************************************************************
** Form generated from reading UI file 'rsa.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSA_H
#define UI_RSA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RSA
{
public:
    QPushButton *ButtonBack;
    QTextEdit *textInput;
    QLabel *label;
    QLineEdit *primeNumber1;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *primeNumber2;
    QLabel *error;

    void setupUi(QWidget *RSA)
    {
        if (RSA->objectName().isEmpty())
            RSA->setObjectName(QStringLiteral("RSA"));
        RSA->resize(723, 328);
        ButtonBack = new QPushButton(RSA);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 290, 111, 28));
        textInput = new QTextEdit(RSA);
        textInput->setObjectName(QStringLiteral("textInput"));
        textInput->setGeometry(QRect(10, 10, 431, 241));
        label = new QLabel(RSA);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 20, 121, 20));
        primeNumber1 = new QLineEdit(RSA);
        primeNumber1->setObjectName(QStringLiteral("primeNumber1"));
        primeNumber1->setGeometry(QRect(590, 10, 113, 28));
        pushButton = new QPushButton(RSA);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(570, 290, 141, 28));
        label_2 = new QLabel(RSA);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 60, 121, 20));
        primeNumber2 = new QLineEdit(RSA);
        primeNumber2->setObjectName(QStringLiteral("primeNumber2"));
        primeNumber2->setGeometry(QRect(590, 60, 113, 28));
        error = new QLabel(RSA);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(10, 260, 431, 20));

        retranslateUi(RSA);

        QMetaObject::connectSlotsByName(RSA);
    } // setupUi

    void retranslateUi(QWidget *RSA)
    {
<<<<<<< HEAD
        RSA->setWindowTitle(QApplication::translate("RSA", "Form", Q_NULLPTR));
        ButtonBack->setText(QApplication::translate("RSA", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", Q_NULLPTR));
        label->setText(QApplication::translate("RSA", "\320\237\321\200\320\276\321\201\321\202\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 1:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RSA", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("RSA", "\320\237\321\200\320\276\321\201\321\202\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 2:", Q_NULLPTR));
        error->setText(QString());
=======
        RSA->setWindowTitle(QApplication::translate("RSA", "Form", 0));
        ButtonBack->setText(QApplication::translate("RSA", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", 0));
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
    } // retranslateUi

};

namespace Ui {
    class RSA: public Ui_RSA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSA_H
