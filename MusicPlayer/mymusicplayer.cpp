#include "mymusicplayer.h"
#include "ui_mymusicplayer.h"
#include <QTextCodec>

MyMusicPlayer::MyMusicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMusicPlayer)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    player = new QMediaPlayer(this);
    playerList = new QMediaPlaylist;
    playerList->addMedia(QUrl(QString::fromLocal8Bit("C:/Users/Administrator/Desktop/Music/五月天 - 我不愿让你一个人.flac") ));
    qDebug() << QString::fromLocal8Bit("C:/Users/Administrator/Desktop/Music/五月天 - 我不愿 让你一个人.flac");

    ui->setupUi(this);
    player->setPlaylist(playerList);
    player->play();
}

MyMusicPlayer::~MyMusicPlayer()
{
    delete ui;
}
