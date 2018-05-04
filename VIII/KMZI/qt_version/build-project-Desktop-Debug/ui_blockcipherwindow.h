/********************************************************************************
** Form generated from reading UI file 'blockcipherwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKCIPHERWINDOW_H
#define UI_BLOCKCIPHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockcipherWindow
{
public:
    QPushButton *ButtonBack;

    void setupUi(QWidget *BlockcipherWindow)
    {
        if (BlockcipherWindow->objectName().isEmpty())
            BlockcipherWindow->setObjectName(QStringLiteral("BlockcipherWindow"));
        BlockcipherWindow->resize(427, 341);
        ButtonBack = new QPushButton(BlockcipherWindow);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 300, 141, 28));

        retranslateUi(BlockcipherWindow);

        QMetaObject::connectSlotsByName(BlockcipherWindow);
    } // setupUi

    void retranslateUi(QWidget *BlockcipherWindow)
    {
        BlockcipherWindow->setWindowTitle(QApplication::translate("BlockcipherWindow", "Form", 0));
        ButtonBack->setText(QApplication::translate("BlockcipherWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class BlockcipherWindow: public Ui_BlockcipherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKCIPHERWINDOW_H
