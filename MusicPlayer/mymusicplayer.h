#ifndef MYMUSICPLAYER_H
#define MYMUSICPLAYER_H
#include <QMediaPlayer>
#include <QMainWindow>
#include <QMediaPlaylist>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <Qtsql/QSqlError>
#include <QVariantList>
namespace Ui {
class MyMusicPlayer;
}

class MyMusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMusicPlayer(QWidget *parent = 0);
    ~MyMusicPlayer();
public slots:
    void pauseStart();
    void addFile();
    void prevSong();
    void nextSong();
    void isVolume();

private:
    Ui::MyMusicPlayer *ui;

    QMediaPlayer *player;
    QMediaPlaylist *playerList;
    bool isPlay;//判断是否正在播放
    int voulumeNow;//用来保存静音前的音量并恢复
    bool isvolume;//记录图标的状态

    //歌曲资源地址
    QUrl url;
    //歌手
    QString author;
    //歌曲名
    QString title;
    //时长
    qint64 duration;
    //唱片集
    QString albumTitle;
    //比特率
    int audioBitRate;

};

#endif // MYMUSICPLAYER_H
