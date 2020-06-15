#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Constants.h"
#include "Platform.h"
#include "Transparent.h"



class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent * event);
    void standup();
    void jump();
     void JumpColliding();
public slots:
    void spawn();
    void move();

public:
    Platform* iniPlatform(int x,int y);
    Transparent* iniCollingRect(int x,int y);
  //  QList<QGraphicsItem *> colliding_items ;
    int state;
private:
    int count;
    int JUMPHIGH;


};

#endif // PLAYER_H
