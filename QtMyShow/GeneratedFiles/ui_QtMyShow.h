/********************************************************************************
** Form generated from reading UI file 'QtMyShow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMYSHOW_H
#define UI_QTMYSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtMyShowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtMyShowClass)
    {
        if (QtMyShowClass->objectName().isEmpty())
            QtMyShowClass->setObjectName(QStringLiteral("QtMyShowClass"));
        QtMyShowClass->resize(600, 400);
        menuBar = new QMenuBar(QtMyShowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtMyShowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtMyShowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtMyShowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtMyShowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtMyShowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtMyShowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtMyShowClass->setStatusBar(statusBar);

        retranslateUi(QtMyShowClass);

        QMetaObject::connectSlotsByName(QtMyShowClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtMyShowClass)
    {
        QtMyShowClass->setWindowTitle(QApplication::translate("QtMyShowClass", "QtMyShow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtMyShowClass: public Ui_QtMyShowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMYSHOW_H
