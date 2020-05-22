#include "mymusicplayer.h"
#include "ui_mymusicplayer.h"
#include <QTextCodec>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QStringList>
#include <QSlider>
#include <QTableWidget>
#include <QFileInfo>


MyMusicPlayer::MyMusicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMusicPlayer)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));//设置中文不乱码



    //================end============================================



    isPlay = false;//初始化不播放
    isvolume = true;//初始化不静音

    player = new QMediaPlayer(this);
    playerList = new QMediaPlaylist;
    playerList->setPlaybackMode(QMediaPlaylist::Loop);

    ui->setupUi(this);
    player->setPlaylist(playerList);
    //player->play();


    connect(ui->psPuse,&QPushButton::clicked,this,&MyMusicPlayer::pauseStart);//播放暂停按钮
    connect(ui->psAddfile,&QPushButton::clicked,this,&MyMusicPlayer::addFile);//添加文件按钮
    connect(ui->pbPrev,&QPushButton::clicked,this,&MyMusicPlayer::prevSong);//上一曲按钮事件
    connect(ui->psNext,&QPushButton::clicked,this,&MyMusicPlayer::nextSong);//下一曲按钮事件
    connect(ui->psVolume,&QPushButton::clicked,this,&MyMusicPlayer::isVolume);//声音按钮静音和开放
    connect(ui->psPlayType,&QPushButton::clicked,this,&MyMusicPlayer::changePlayType);//播放模式的更换
    connect(ui->slProcess,&QSlider::sliderMoved,this,&MyMusicPlayer::sliderChange);//slider的手动滑动改变歌曲播放的进度
    connect(player,&QMediaPlayer::durationChanged,this,&MyMusicPlayer::setSliderMaxnumber);//取得歌曲总时长，并设置slider的取值范围
    connect(player,&QMediaPlayer::positionChanged,this,&MyMusicPlayer::changeSliderProcess);//当歌曲的当前s改变，修改slider的值
           //void durationChanged(qint64 duration)



    //=============tablewidget初始化相关操作======================
    QStringList header;
    ui->infoSong->setRowCount(0);
    ui->infoSong->setColumnCount(4); //设置列数为5
    qDebug() << "here";
    header << "歌曲名" << "艺术家" << "唱片集" << "时长";

    ui->infoSong->setHorizontalHeaderLabels(header);


    showSongs();
}

MyMusicPlayer::~MyMusicPlayer()
{
    delete ui;
    delete player;
    delete playerList;
    db.close();

}

void MyMusicPlayer::showSongs()
{


    //==============数据库相关操作======================================
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("C:/Users/Administrator/Desktop/myproject/MusicPlayer/MusicPlayer/info.db");
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
        int row = ui->infoSong->rowCount();

        ui->infoSong->insertRow(row);

        ui->infoSong->setItem(row,0,new QTableWidgetItem(query.value(1).toString()));
        ui->infoSong->setItem(row,1,new QTableWidgetItem(query.value(2).toString()));
        ui->infoSong->setItem(row,2,new QTableWidgetItem(query.value(3).toString()));
        ui->infoSong->setItem(row,3,new QTableWidgetItem(query.value(4).toString()));
        playerList->addMedia(QUrl(query.value(0).toString()));

        //取出当前行的内容
//        qDebug() << query.value(0).toString()
//                 << query.value(1)
//                 << query.value(2)
//                 << query.value(3)
//                 << query.value(4).toInt();
    }

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
    QString path = QFileDialog::getOpenFileName(this,"open","../","TXT(*.mp3 *.flac *.ape *.wav)");
    QString filepath;
    filepath = "file:///"+path;
    QMediaPlayer tempPlayer;
    tempPlayer.setMedia(QUrl(filepath));

    qDebug() << filepath << endl;



    //元数据的解析需要时间，所以这里需要循环等待（但同时需要保持Qt事件处理机制在运行）
    while(!tempPlayer.isMetaDataAvailable()){
        QCoreApplication::processEvents();
    }

    QStringList list=tempPlayer.availableMetaData();//调试时查看有哪些元数据可用

    if(tempPlayer.isMetaDataAvailable()){
        //歌曲信息
        author = tempPlayer.metaData(QStringLiteral("Author")).toStringList().join(",");

        title = tempPlayer.metaData(QStringLiteral("Title")).toString();
        albumTitle = tempPlayer.metaData(QStringLiteral("AlbumTitle")).toString();
        audioBitRate = tempPlayer.metaData(QStringLiteral("AudioBitRate")).toInt();
        duration=tempPlayer.duration();

        int row = ui->infoSong->rowCount();

        ui->infoSong->insertRow(row);

        ui->infoSong->setItem(row,0,new QTableWidgetItem(title));
        ui->infoSong->setItem(row,1,new QTableWidgetItem(author));
        ui->infoSong->setItem(row,2,new QTableWidgetItem(albumTitle));
        ui->infoSong->setItem(row,3,new QTableWidgetItem(QString::number(duration)));
        playerList->addMedia(QUrl(path));   //如果可以加入数据库再进行添加到播放列表
    }


    //打开数据库
    if(!db.open())
    {
        //QMessageBox::information(this,QString::fromLocal8Bit("错误"),db.lastError(),QMessageBox::Ok);
        qDebug() << "de open is error" << endl;
        return ;
    }

    QSqlQuery query;
    QString a = "woshishei";
    QString order = QString("insert into musicInfo values ('%1','%2','%3','%4',%5);").arg(path,title,author,albumTitle, QString::number(duration));
    qDebug() << "order is" << endl;
    qDebug() << order  << endl;
    qDebug() << a << endl;
    if(query.exec(order) == false)
    {
        qDebug() << "default" << endl;
    }

    qDebug() << "this is song info:" << endl;
    qDebug() << path << endl;
    qDebug() << author << title <<
    albumTitle<<  audioBitRate    << duration;

}

void MyMusicPlayer::prevSong()
{
    int currentIndex=playerList->currentIndex();
    if(--currentIndex<0)
    {
        currentIndex=playerList->mediaCount()-1;
    }
    playerList->setCurrentIndex(currentIndex);
    player->play();
}

void MyMusicPlayer::nextSong()
{
    int currentIndex=playerList->currentIndex();
    if(++currentIndex==playerList->mediaCount()) currentIndex=0;
    playerList->setCurrentIndex(currentIndex);
    player->play();
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

void MyMusicPlayer::changePlayType()
{
    //qDebug() << playerList->playbackMode();
    switch (playerList->playbackMode()) {
    case QMediaPlaylist::CurrentItemInLoop:
    {
        playerList->setPlaybackMode(QMediaPlaylist::Loop);
        ui->psPlayType->setStyleSheet("border-image: url(:/img/loop.png);");

        break;
    }
    case QMediaPlaylist::Loop:
    {
        playerList->setPlaybackMode(QMediaPlaylist::Random);
        ui->psPlayType->setStyleSheet("border-image: url(:/img/random.png);");
        break;
    }
    case QMediaPlaylist::Random:
    {
        playerList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        ui->psPlayType->setStyleSheet("border-image: url(:/img/singleloop.png);");
        break;
    }
    default:
        break;
    }
}

void MyMusicPlayer::sliderChange(int position)
{
    player->setPosition(position);
}

void MyMusicPlayer::changeSliderProcess(qint64 duration)
{
    ui->slProcess->setValue(duration);
}

void MyMusicPlayer::setSliderMaxnumber(qint64 duration)
{
    ui->slProcess->setMaximum(duration);
}

