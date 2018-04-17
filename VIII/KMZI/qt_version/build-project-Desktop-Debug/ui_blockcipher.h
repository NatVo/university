/********************************************************************************
** Form generated from reading UI file 'blockcipher.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKCIPHER_H
#define UI_BLOCKCIPHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockCipher
{
public:
    QPushButton *ButtonBack;

    void setupUi(QWidget *BlockCipher)
    {
        if (BlockCipher->objectName().isEmpty())
            BlockCipher->setObjectName(QStringLiteral("BlockCipher"));
        BlockCipher->resize(400, 300);
        ButtonBack = new QPushButton(BlockCipher);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 260, 121, 28));

        retranslateUi(BlockCipher);

        QMetaObject::connectSlotsByName(BlockCipher);
    } // setupUi

    void retranslateUi(QWidget *BlockCipher)
    {
        BlockCipher->setWindowTitle(QApplication::translate("BlockCipher", "Form", Q_NULLPTR));
        ButtonBack->setText(QApplication::translate("BlockCipher", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BlockCipher: public Ui_BlockCipher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKCIPHER_H
