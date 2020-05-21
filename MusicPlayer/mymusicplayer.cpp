#include "mymusicplayer.h"
#include "ui_mymusicplayer.h"
#include <QTextCodec>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

MyMusicPlayer::MyMusicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMusicPlayer)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));//设置中文不乱码
    //==============数据库相关操作======================================
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("./info.db");
    //打开数据库
    if(!db.open())
    {
        //QMessageBox::information(this,QString::fromLocal8Bit("错误"),db.lastError(),QMessageBox::Ok);
        return ;
    }
    QSqlQuery query;
    //query.exec("create table musicInfo(songname varchar(20),singer varchar(20)),album varchar(10),durantion int);");//创建表格
    query.exec("select * from musicInfo");
    while(query.next())//一行一行的遍历
    {
        //取出当前行的内容
        qDebug() << query.value(0)
                 << query.value(1)
                 << query.value(2)
                 << query.value(3)
                 << query.value(4).toInt();
    }


    //================end============================================



    isPlay = false;//初始化不播放
    isvolume = true;//初始化不静音

    player = new QMediaPlayer(this);
    playerList = new QMediaPlaylist;

    ui->setupUi(this);
    player->setPlaylist(playerList);
    //player->play();


    connect(ui->psPuse,&QPushButton::clicked,this,&MyMusicPlayer::pauseStart);//播放暂停按钮
    connect(ui->psAddfile,&QPushButton::clicked,this,&MyMusicPlayer::addFile);//添加文件按钮
    connect(ui->pbPrev,&QPushButton::clicked,this,&MyMusicPlayer::prevSong);//上一曲按钮事件
    connect(ui->psNext,&QPushButton::clicked,this,&MyMusicPlayer::nextSong);//下一曲按钮事件
    connect(ui->psVolume,&QPushButton::clicked,this,&MyMusicPlayer::isVolume);//声音按钮静音和开放
}

MyMusicPlayer::~MyMusicPlayer()
{
    delete ui;
    delete player;
    delete playerList;
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
        qDebug() << path;
    }

    QMediaPlayer tempPlayer;
    tempPlayer.setMedia(QUrl(path));
    //元数据的解析需要时间，所以这里需要循环等待（但同时需要保持Qt事件处理机制在运行）
    while(!tempPlayer.isMetaDataAvailable()){
        QCoreApplication::processEvents();
    }
    QStringList list=tempPlayer.availableMetaData();//调试时查看有哪些元数据可用
    if(tempPlayer.isMetaDataAvailable()){
        //歌曲信息
        author = tempPlayer.metaData(QStringLiteral("Author")).toStringList().join(",");
        //author = tempPlayer.metaData(QStringLiteral("Author")).toString(); //查手册发现，这里返回的是StringList
        //author=tempPlayer.metaData(QStringLiteral("ContributingArtist")).toStringList().join(","); //另一种元数据
        title = tempPlayer.metaData(QStringLiteral("Title")).toString();
        albumTitle = tempPlayer.metaData(QStringLiteral("AlbumTitle")).toString();
        audioBitRate = tempPlayer.metaData(QStringLiteral("AudioBitRate")).toInt();
        duration=tempPlayer.duration();
    }
    qDebug() << "this is song info:" << endl;
    qDebug() << path << endl;
    qDebug() << author << title <<
    albumTitle<<  audioBitRate    << duration;

}

void MyMusicPlayer::prevSong()
{
    //设置列表的当前下标为下一首，貌似这个函数会自动检测下标索引在歌曲下标的范围之内
    playerList->setCurrentIndex(playerList->currentIndex()-1);
}

void MyMusicPlayer::nextSong()
{
    playerList->setCurrentIndex(playerList->currentIndex()+1);
}

void MyMusicPlayer::isVolume()
{
    if(isvolume == false)//静音的时候按下
    {
        player->setVolume(voulumeNow);
        ui->psVolume->setStyleSheet("border-image: url(:/img/soundsize.png);");
        isvolume = true;
    }
    else//没有静音的时候按下
    {
        voulumeNow = player->volume();
        player->setVolume(0);
        ui->psVolume->setStyleSheet("border-image: url(:/img/mute.png);");
        isvolume = false;
    }
}

