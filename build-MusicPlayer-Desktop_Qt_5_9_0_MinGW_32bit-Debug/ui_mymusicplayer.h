/********************************************************************************
** Form generated from reading UI file 'mymusicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMUSICPLAYER_H
#define UI_MYMUSICPLAYER_H

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

class Ui_MyMusicPlayer
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMusicPlayer)
    {
        if (MyMusicPlayer->objectName().isEmpty())
            MyMusicPlayer->setObjectName(QStringLiteral("MyMusicPlayer"));
        MyMusicPlayer->resize(400, 300);
        menuBar = new QMenuBar(MyMusicPlayer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyMusicPlayer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyMusicPlayer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyMusicPlayer->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyMusicPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyMusicPlayer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyMusicPlayer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyMusicPlayer->setStatusBar(statusBar);

        retranslateUi(MyMusicPlayer);

        QMetaObject::connectSlotsByName(MyMusicPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *MyMusicPlayer)
    {
        MyMusicPlayer->setWindowTitle(QApplication::translate("MyMusicPlayer", "MyMusicPlayer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyMusicPlayer: public Ui_MyMusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMUSICPLAYER_H
