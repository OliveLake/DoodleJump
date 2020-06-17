#include "Monster.h"
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QDebug>

Monster::Monster(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
     setPixmap(QPixmap(":/new/prefix1/image/blue_monster_left.png"));
}
