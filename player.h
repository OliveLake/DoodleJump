#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Constants.h"


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void iniPlatform();
    void standup();
    void jump();
public slots:
    void spawn();
    void AutoJump();
private:
    int count;
    int state;
    int JUMPHIGH;

};

#endif // PLAYER_H
