#ifndef MYMUSICPLAYER_H
#define MYMUSICPLAYER_H
#include <QMediaPlayer>
#include <QMainWindow>
#include <QMediaPlaylist>

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

private:
    Ui::MyMusicPlayer *ui;

    QMediaPlayer *player;
    QMediaPlaylist *playerList;
    bool isPlay;//判断是否正在播放
};

#endif // MYMUSICPLAYER_H
