/********************************************************************************
** Form generated from reading UI file 'vernamwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERNAMWINDOW_H
#define UI_VERNAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VernamWindow
{
public:
    QPushButton *ButtonBack;

    void setupUi(QWidget *VernamWindow)
    {
        if (VernamWindow->objectName().isEmpty())
            VernamWindow->setObjectName(QStringLiteral("VernamWindow"));
        VernamWindow->resize(400, 300);
        ButtonBack = new QPushButton(VernamWindow);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 260, 99, 27));

        retranslateUi(VernamWindow);

        QMetaObject::connectSlotsByName(VernamWindow);
    } // setupUi

    void retranslateUi(QWidget *VernamWindow)
    {
        VernamWindow->setWindowTitle(QApplication::translate("VernamWindow", "Form", 0));
        ButtonBack->setText(QApplication::translate("VernamWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class VernamWindow: public Ui_VernamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERNAMWINDOW_H
