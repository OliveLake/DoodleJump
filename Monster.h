#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Transparent.h"

class Monster: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Monster(QGraphicsItem * parent=0);

};

#endif // MONSTER_H
