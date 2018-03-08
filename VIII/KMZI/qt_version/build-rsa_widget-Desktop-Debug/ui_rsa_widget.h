/********************************************************************************
** Form generated from reading UI file 'rsa_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSA_WIDGET_H
#define UI_RSA_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RSA_widget
{
public:
    QWidget *centralWidget;
    QTextEdit *textInput;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *primeNumber1;
    QLineEdit *primeNumber2;
    QLabel *error;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RSA_widget)
    {
        if (RSA_widget->objectName().isEmpty())
            RSA_widget->setObjectName(QStringLiteral("RSA_widget"));
        RSA_widget->resize(796, 354);
        centralWidget = new QWidget(RSA_widget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textInput = new QTextEdit(centralWidget);
        textInput->setObjectName(QStringLiteral("textInput"));
        textInput->setGeometry(QRect(20, 10, 511, 241));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 250, 141, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 20, 121, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 60, 121, 20));
        primeNumber1 = new QLineEdit(centralWidget);
        primeNumber1->setObjectName(QStringLiteral("primeNumber1"));
        primeNumber1->setGeometry(QRect(670, 10, 113, 28));
        primeNumber2 = new QLineEdit(centralWidget);
        primeNumber2->setObjectName(QStringLiteral("primeNumber2"));
        primeNumber2->setGeometry(QRect(670, 50, 113, 28));
        error = new QLabel(centralWidget);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(20, 260, 511, 20));
        RSA_widget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RSA_widget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 796, 25));
        RSA_widget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RSA_widget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RSA_widget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RSA_widget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RSA_widget->setStatusBar(statusBar);

        retranslateUi(RSA_widget);

        QMetaObject::connectSlotsByName(RSA_widget);
    } // setupUi

    void retranslateUi(QMainWindow *RSA_widget)
    {
        RSA_widget->setWindowTitle(QApplication::translate("RSA_widget", "RSA_widget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RSA_widget", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("RSA_widget", "\320\237\321\200\320\276\321\201\321\202\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 1:", Q_NULLPTR));
        label_2->setText(QApplication::translate("RSA_widget", "\320\237\321\200\320\276\321\201\321\202\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 2:", Q_NULLPTR));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RSA_widget: public Ui_RSA_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSA_WIDGET_H
