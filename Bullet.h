#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Constants.h"
//create signal & slot -> 1.include QObject 2.create QObject

class Bullet:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT;
public:
    Bullet(QGraphicsItem * parent=0);

public slots:
    void move();

private:

};

#endif // BULLET_H
