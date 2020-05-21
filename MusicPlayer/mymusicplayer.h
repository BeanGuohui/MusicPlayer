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

private:
    Ui::MyMusicPlayer *ui;

    QMediaPlayer *player;
    QMediaPlaylist *playerList;
};

#endif // MYMUSICPLAYER_H
