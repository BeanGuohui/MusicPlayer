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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMusicPlayer
{
public:
    QAction *actionaddFile;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *showNowSong;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *infoSong;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QSlider *slProcess;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *lanow;
    QLabel *lbding;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *psAddfile;
    QPushButton *psPlayType;
    QPushButton *pbPrev;
    QPushButton *psPuse;
    QPushButton *psNext;
    QPushButton *psVolume;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMusicPlayer)
    {
        if (MyMusicPlayer->objectName().isEmpty())
            MyMusicPlayer->setObjectName(QStringLiteral("MyMusicPlayer"));
        MyMusicPlayer->resize(956, 557);
        MyMusicPlayer->setStyleSheet(QLatin1String("#centralWidget{\n"
"border-image: url(:/img/backimg.jpg);\n"
"}"));
        actionaddFile = new QAction(MyMusicPlayer);
        actionaddFile->setObjectName(QStringLiteral("actionaddFile"));
        centralWidget = new QWidget(MyMusicPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        showNowSong = new QLabel(widget_5);
        showNowSong->setObjectName(QStringLiteral("showNowSong"));

        horizontalLayout->addWidget(showNowSong);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_5);

        infoSong = new QTableWidget(centralWidget);
        infoSong->setObjectName(QStringLiteral("infoSong"));
        infoSong->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0);"));

        verticalLayout_2->addWidget(infoSong);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        slProcess = new QSlider(widget_2);
        slProcess->setObjectName(QStringLiteral("slProcess"));
        slProcess->setMaximum(100);
        slProcess->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slProcess);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        lanow = new QLabel(widget_4);
        lanow->setObjectName(QStringLiteral("lanow"));

        horizontalLayout_3->addWidget(lanow);

        lbding = new QLabel(widget_4);
        lbding->setObjectName(QStringLiteral("lbding"));

        horizontalLayout_3->addWidget(lbding);


        verticalLayout->addWidget(widget_4);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        psAddfile = new QPushButton(widget_3);
        psAddfile->setObjectName(QStringLiteral("psAddfile"));
        psAddfile->setMinimumSize(QSize(50, 50));
        psAddfile->setMaximumSize(QSize(50, 50));
        psAddfile->setStyleSheet(QStringLiteral("border-image: url(:/img/file.png);"));

        horizontalLayout_2->addWidget(psAddfile);

        psPlayType = new QPushButton(widget_3);
        psPlayType->setObjectName(QStringLiteral("psPlayType"));
        psPlayType->setMinimumSize(QSize(50, 50));
        psPlayType->setMaximumSize(QSize(50, 50));
        psPlayType->setStyleSheet(QStringLiteral("border-image: url(:/img/loop.png);"));

        horizontalLayout_2->addWidget(psPlayType);

        pbPrev = new QPushButton(widget_3);
        pbPrev->setObjectName(QStringLiteral("pbPrev"));
        pbPrev->setMinimumSize(QSize(50, 50));
        pbPrev->setMaximumSize(QSize(50, 50));
        pbPrev->setStyleSheet(QStringLiteral("border-image: url(:/img/prev.png);"));

        horizontalLayout_2->addWidget(pbPrev);

        psPuse = new QPushButton(widget_3);
        psPuse->setObjectName(QStringLiteral("psPuse"));
        psPuse->setMinimumSize(QSize(50, 50));
        psPuse->setMaximumSize(QSize(50, 50));
        psPuse->setStyleSheet(QStringLiteral("border-image: url(:/img/play.png);"));

        horizontalLayout_2->addWidget(psPuse);

        psNext = new QPushButton(widget_3);
        psNext->setObjectName(QStringLiteral("psNext"));
        psNext->setMinimumSize(QSize(50, 50));
        psNext->setMaximumSize(QSize(50, 50));
        psNext->setStyleSheet(QStringLiteral("border-image: url(:/img/next.png);"));

        horizontalLayout_2->addWidget(psNext);

        psVolume = new QPushButton(widget_3);
        psVolume->setObjectName(QStringLiteral("psVolume"));
        psVolume->setMinimumSize(QSize(50, 50));
        psVolume->setMaximumSize(QSize(50, 50));
        psVolume->setStyleSheet(QStringLiteral("border-image: url(:/img/soundsize.png);"));

        horizontalLayout_2->addWidget(psVolume);


        verticalLayout_2->addWidget(widget_3);

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
        showNowSong->setText(QApplication::translate("MyMusicPlayer", "TextLabel", Q_NULLPTR));
        lanow->setText(QApplication::translate("MyMusicPlayer", "TextLabel", Q_NULLPTR));
        lbding->setText(QApplication::translate("MyMusicPlayer", "TextLabel", Q_NULLPTR));
        psAddfile->setText(QString());
        psPlayType->setText(QString());
        pbPrev->setText(QString());
        psPuse->setText(QString());
        psNext->setText(QString());
        psVolume->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyMusicPlayer: public Ui_MyMusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMUSICPLAYER_H
