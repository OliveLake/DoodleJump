#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Constants.h"
#include "Monster.h"
//create signal & slot -> 1.include QObject 2.create QObject

class Bullet:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT;
public:
    Bullet(QGraphicsItem * parent=0);
    Monster * mon;
public slots:
    void move();

void collid();

};

#endif // BULLET_H
