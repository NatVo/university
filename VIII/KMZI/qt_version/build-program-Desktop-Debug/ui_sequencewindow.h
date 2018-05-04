/********************************************************************************
** Form generated from reading UI file 'sequencewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEQUENCEWINDOW_H
#define UI_SEQUENCEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SequenceWindow
{
public:
    QPushButton *ButtonBack;

    void setupUi(QWidget *SequenceWindow)
    {
        if (SequenceWindow->objectName().isEmpty())
            SequenceWindow->setObjectName(QStringLiteral("SequenceWindow"));
        SequenceWindow->resize(400, 300);
        ButtonBack = new QPushButton(SequenceWindow);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 260, 99, 27));

        retranslateUi(SequenceWindow);

        QMetaObject::connectSlotsByName(SequenceWindow);
    } // setupUi

    void retranslateUi(QWidget *SequenceWindow)
    {
        SequenceWindow->setWindowTitle(QApplication::translate("SequenceWindow", "Form", 0));
        ButtonBack->setText(QApplication::translate("SequenceWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class SequenceWindow: public Ui_SequenceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEQUENCEWINDOW_H
