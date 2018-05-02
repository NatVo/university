/********************************************************************************
** Form generated from reading UI file 'rsawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSAWINDOW_H
#define UI_RSAWINDOW_H

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

class Ui_RSAWindow
{
public:
    QPushButton *ButtonBack;
    QLabel *label_2;
    QTextEdit *textInput;
    QLineEdit *primeNumber1;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *error;
    QLineEdit *primeNumber2;

    void setupUi(QWidget *RSAWindow)
    {
        if (RSAWindow->objectName().isEmpty())
            RSAWindow->setObjectName(QStringLiteral("RSAWindow"));
        RSAWindow->resize(790, 298);
        ButtonBack = new QPushButton(RSAWindow);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(640, 220, 141, 28));
        label_2 = new QLabel(RSAWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 60, 121, 20));
        textInput = new QTextEdit(RSAWindow);
        textInput->setObjectName(QStringLiteral("textInput"));
        textInput->setGeometry(QRect(10, 10, 511, 241));
        primeNumber1 = new QLineEdit(RSAWindow);
        primeNumber1->setObjectName(QStringLiteral("primeNumber1"));
        primeNumber1->setGeometry(QRect(660, 10, 113, 28));
        pushButton = new QPushButton(RSAWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(640, 170, 141, 28));
        label = new QLabel(RSAWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(530, 20, 121, 20));
        error = new QLabel(RSAWindow);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(10, 260, 511, 20));
        primeNumber2 = new QLineEdit(RSAWindow);
        primeNumber2->setObjectName(QStringLiteral("primeNumber2"));
        primeNumber2->setGeometry(QRect(660, 50, 113, 28));

        retranslateUi(RSAWindow);

        QMetaObject::connectSlotsByName(RSAWindow);
    } // setupUi

    void retranslateUi(QWidget *RSAWindow)
    {
        RSAWindow->setWindowTitle(QApplication::translate("RSAWindow", "Form", Q_NULLPTR));
        ButtonBack->setText(QApplication::translate("RSAWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("RSAWindow", "\320\237\321\200\320\276\321\201\321\202\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 2:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RSAWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("RSAWindow", "\320\237\321\200\320\276\321\201\321\202\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 1:", Q_NULLPTR));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RSAWindow: public Ui_RSAWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSAWINDOW_H
