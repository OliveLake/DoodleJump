#include "Gameover.h"
#include "Constants.h"
#include <QGraphicsScene>

Gameover::Gameover(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/prefix1/image/gameover"));
}
