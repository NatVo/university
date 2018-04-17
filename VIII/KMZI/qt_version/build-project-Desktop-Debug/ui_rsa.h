/********************************************************************************
** Form generated from reading UI file 'rsa.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RSA
{
public:
    QPushButton *ButtonBack;

    void setupUi(QWidget *RSA)
    {
        if (RSA->objectName().isEmpty())
            RSA->setObjectName(QStringLiteral("RSA"));
        RSA->resize(400, 300);
        ButtonBack = new QPushButton(RSA);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 260, 111, 28));

        retranslateUi(RSA);

        QMetaObject::connectSlotsByName(RSA);
    } // setupUi

    void retranslateUi(QWidget *RSA)
    {
        RSA->setWindowTitle(QApplication::translate("RSA", "Form", Q_NULLPTR));
        ButtonBack->setText(QApplication::translate("RSA", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RSA: public Ui_RSA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSA_H
