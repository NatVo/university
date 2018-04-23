/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ButtonSequence;
    QPushButton *ButtonBerlikamp;
    QPushButton *ButtonRSA;
    QPushButton *ButtonVernam;
    QPushButton *ButtonBlockCipher;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(363, 310);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ButtonSequence = new QPushButton(centralWidget);
        ButtonSequence->setObjectName(QStringLiteral("ButtonSequence"));
        ButtonSequence->setGeometry(QRect(10, 190, 161, 41));
        ButtonBerlikamp = new QPushButton(centralWidget);
        ButtonBerlikamp->setObjectName(QStringLiteral("ButtonBerlikamp"));
        ButtonBerlikamp->setGeometry(QRect(190, 10, 161, 41));
        ButtonRSA = new QPushButton(centralWidget);
        ButtonRSA->setObjectName(QStringLiteral("ButtonRSA"));
        ButtonRSA->setGeometry(QRect(10, 130, 161, 41));
        ButtonVernam = new QPushButton(centralWidget);
        ButtonVernam->setObjectName(QStringLiteral("ButtonVernam"));
        ButtonVernam->setGeometry(QRect(10, 10, 161, 41));
        ButtonBlockCipher = new QPushButton(centralWidget);
        ButtonBlockCipher->setObjectName(QStringLiteral("ButtonBlockCipher"));
        ButtonBlockCipher->setGeometry(QRect(10, 70, 161, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 363, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ButtonSequence->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\270", 0));
        ButtonBerlikamp->setText(QString());
        ButtonRSA->setText(QApplication::translate("MainWindow", "RSA + \320\255\320\246\320\237", 0));
        ButtonVernam->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\320\260\320\274", 0));
        ButtonBlockCipher->setText(QApplication::translate("MainWindow", "\320\221\320\273\320\276\321\207\320\275\321\213\320\265 \321\210\320\270\321\204\321\200\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
