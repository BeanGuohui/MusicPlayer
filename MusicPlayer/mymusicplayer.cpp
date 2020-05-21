#include "mymusicplayer.h"
#include "ui_mymusicplayer.h"
#include <QTextCodec>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
MyMusicPlayer::MyMusicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMusicPlayer)
{
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));//设置中文不乱码
    isPlay = false;//初始化不播放

    player = new QMediaPlayer(this);
    playerList = new QMediaPlaylist;



    ui->setupUi(this);
    player->setPlaylist(playerList);
    //player->play();


    connect(ui->psPuse,&QPushButton::clicked,this,&MyMusicPlayer::pauseStart);//播放暂停按钮
    connect(ui->psAddfile,&QPushButton::clicked,this,&MyMusicPlayer::addFile);//添加文件按钮
    connect(ui->pbPrev,&QPushButton::clicked,this,&MyMusicPlayer::prevSong);//上一曲按钮事件
        connect(ui->psNext,&QPushButton::clicked,this,&MyMusicPlayer::nextSong);//下一曲按钮事件
}

MyMusicPlayer::~MyMusicPlayer()
{
    delete ui;
}

void MyMusicPlayer::pauseStart()
{
    if(playerList->isEmpty())
    {
        QMessageBox::information(this,"温馨提示","播放列表没有歌曲,请先添加歌曲！",QMessageBox::Ok);
        return;
    }
    if(isPlay == false)
    {
        player->play();
        ui->psPuse->setStyleSheet("border-image: url(:/img/pause.png);");
        isPlay = true;
    }
    else{
        player->pause();
         ui->psPuse->setStyleSheet("border-image: url(:/img/play.png);");
         isPlay = false;
    }
}

void MyMusicPlayer::addFile()
{
    QFile file(this);
    QString path = QFileDialog::getOpenFileName(this,"open","../","TXT(*.mp3 *.flac)");
    if(path.isEmpty() == false)
    {
        playerList->addMedia(QUrl(path));
                //playerList->addMedia(QUrl(QString::fromLocal8Bit("C:/Users/Administrator/Desktop/Music/五月天 - 我不愿让你一个人.flac") ));

        qDebug() << path;
    }

}

void MyMusicPlayer::prevSong()
{
    playerList->setCurrentIndex(playerList->currentIndex()-1);
    player->play();
}

void MyMusicPlayer::nextSong()
{
    playerList->setCurrentIndex(playerList->currentIndex()+1);
    player->play();
}
