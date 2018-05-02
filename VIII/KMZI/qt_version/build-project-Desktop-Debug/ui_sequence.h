/********************************************************************************
** Form generated from reading UI file 'sequence.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEQUENCE_H
#define UI_SEQUENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sequence
{
public:
    QPushButton *ButtonBack;

    void setupUi(QWidget *Sequence)
    {
        if (Sequence->objectName().isEmpty())
            Sequence->setObjectName(QStringLiteral("Sequence"));
        Sequence->resize(400, 300);
        ButtonBack = new QPushButton(Sequence);
        ButtonBack->setObjectName(QStringLiteral("ButtonBack"));
        ButtonBack->setGeometry(QRect(10, 260, 111, 28));

        retranslateUi(Sequence);

        QMetaObject::connectSlotsByName(Sequence);
    } // setupUi

    void retranslateUi(QWidget *Sequence)
    {
        Sequence->setWindowTitle(QApplication::translate("Sequence", "Form", Q_NULLPTR));
        ButtonBack->setText(QApplication::translate("Sequence", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Sequence: public Ui_Sequence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEQUENCE_H
