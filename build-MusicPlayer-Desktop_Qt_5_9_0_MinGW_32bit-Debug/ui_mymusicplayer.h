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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMusicPlayer
{
public:
    QAction *actionaddFile;
    QWidget *centralWidget;
    QPushButton *psPuse;
    QPushButton *psAddfile;
    QPushButton *pbPrev;
    QPushButton *psNext;
    QPushButton *psVolume;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *infoSong;
    QPushButton *psPlayType;
    QSlider *slProcess;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMusicPlayer)
    {
        if (MyMusicPlayer->objectName().isEmpty())
            MyMusicPlayer->setObjectName(QStringLiteral("MyMusicPlayer"));
        MyMusicPlayer->resize(888, 519);
        MyMusicPlayer->setStyleSheet(QLatin1String("#centralWidget{\n"
"border-image: url(:/img/backimg.jpg);\n"
"}"));
        actionaddFile = new QAction(MyMusicPlayer);
        actionaddFile->setObjectName(QStringLiteral("actionaddFile"));
        centralWidget = new QWidget(MyMusicPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        psPuse = new QPushButton(centralWidget);
        psPuse->setObjectName(QStringLiteral("psPuse"));
        psPuse->setGeometry(QRect(410, 390, 50, 50));
        psPuse->setMinimumSize(QSize(50, 50));
        psPuse->setMaximumSize(QSize(50, 50));
        psPuse->setStyleSheet(QStringLiteral("border-image: url(:/img/play.png);"));
        psAddfile = new QPushButton(centralWidget);
        psAddfile->setObjectName(QStringLiteral("psAddfile"));
        psAddfile->setGeometry(QRect(130, 390, 50, 50));
        psAddfile->setMinimumSize(QSize(50, 50));
        psAddfile->setMaximumSize(QSize(50, 50));
        psAddfile->setStyleSheet(QStringLiteral("border-image: url(:/img/file.png);"));
        pbPrev = new QPushButton(centralWidget);
        pbPrev->setObjectName(QStringLiteral("pbPrev"));
        pbPrev->setGeometry(QRect(330, 390, 50, 50));
        pbPrev->setMinimumSize(QSize(50, 50));
        pbPrev->setMaximumSize(QSize(50, 50));
        pbPrev->setStyleSheet(QStringLiteral("border-image: url(:/img/prev.png);"));
        psNext = new QPushButton(centralWidget);
        psNext->setObjectName(QStringLiteral("psNext"));
        psNext->setGeometry(QRect(500, 390, 50, 50));
        psNext->setMinimumSize(QSize(50, 50));
        psNext->setMaximumSize(QSize(50, 50));
        psNext->setStyleSheet(QStringLiteral("border-image: url(:/img/next.png);"));
        psVolume = new QPushButton(centralWidget);
        psVolume->setObjectName(QStringLiteral("psVolume"));
        psVolume->setGeometry(QRect(700, 400, 50, 50));
        psVolume->setMinimumSize(QSize(50, 50));
        psVolume->setMaximumSize(QSize(50, 50));
        psVolume->setStyleSheet(QStringLiteral("border-image: url(:/img/soundsize.png);"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(160, 70, 641, 281));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        infoSong = new QTableWidget(widget);
        infoSong->setObjectName(QStringLiteral("infoSong"));
        infoSong->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0);"));

        horizontalLayout->addWidget(infoSong);

        psPlayType = new QPushButton(centralWidget);
        psPlayType->setObjectName(QStringLiteral("psPlayType"));
        psPlayType->setGeometry(QRect(40, 300, 50, 50));
        psPlayType->setMinimumSize(QSize(50, 50));
        psPlayType->setMaximumSize(QSize(50, 50));
        psPlayType->setStyleSheet(QStringLiteral("border-image: url(:/img/loop.png);"));
        slProcess = new QSlider(centralWidget);
        slProcess->setObjectName(QStringLiteral("slProcess"));
        slProcess->setGeometry(QRect(89, 360, 761, 22));
        slProcess->setMaximum(100);
        slProcess->setOrientation(Qt::Horizontal);
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
        actionaddFile->setText(QApplication::translate("MyMusicPlayer", "\346\267\273\345\212\240\346\226\207\344\273\266", Q_NULLPTR));
        psPuse->setText(QString());
        psAddfile->setText(QString());
        pbPrev->setText(QString());
        psNext->setText(QString());
        psVolume->setText(QString());
        psPlayType->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyMusicPlayer: public Ui_MyMusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMUSICPLAYER_H
