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

class Ui_BlockCipherWindow
{
public:
    QPushButton *ButtonBack;

    void setupUi(QWidget *BlockCipherWindow)
    {
        if (BlockCipherWindow->objectName().isEmpty())
            BlockCipherWindow->setObjectName(QStringLiteral("BlockCipherWindow"));
        BlockCipherWindow->resize(400, 300);
        ButtonBack = new QPushButton(BlockCipherWindow);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 260, 99, 27));

        retranslateUi(BlockCipherWindow);

        QMetaObject::connectSlotsByName(BlockCipherWindow);
    } // setupUi

    void retranslateUi(QWidget *BlockCipherWindow)
    {
        BlockCipherWindow->setWindowTitle(QApplication::translate("BlockCipherWindow", "Form", 0));
        ButtonBack->setText(QApplication::translate("BlockCipherWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class BlockCipherWindow: public Ui_BlockCipherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKCIPHERWINDOW_H
