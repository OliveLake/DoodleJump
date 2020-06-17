#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "Constants.h"
#include "Platform.h"
#include "Score.h"
#include "Spring.h"
#include "Transparent.h"
#include "Gameover.h"



class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent * event);
//    void keyReleaseEvent(QKeyEvent *event);
    void checkMove();
    void standup();
    void jump();
     void JumpColliding();
     void iniScore();
     void ChangeCloth();

public slots:
    void spawn();
    void move();

public:
    Platform* iniPlatform(int x,int y);
    Transparent* iniCollingRect(int x,int y);
    Spring* iniSpring(int x,int y);
    Platform* p[10];
    Spring* s[2];
  //  QList<QGraphicsItem *> colliding_items ;
    int state;
private:
    int playerState;
    int playerSpeed = 5;
    int playerCount = 0;
    int playerSpringcount;
    int cameraSpeed = 0;
    int JUMPHIGH;
    int dy;
    int pX;
    bool checkposition;
    bool release_left;
    bool release_right;
    bool press_left;
    bool press_right;
    Score * score;
    Gameover* gameover;

//    QMediaPlayer * music = new QMediaPlayer();


};

#endif // PLAYER_H
