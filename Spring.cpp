#include "Constants.h"
#include "Spring.h"
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QDebug>

Spring::Spring(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

     QPixmap Pixmap(":/new/prefix1/image/spring.png");
     QPixmap pic(QPixmap(Pixmap).scaled(30, 30, Qt::IgnoreAspectRatio,Qt::FastTransformation));
     setPixmap(pic);
}
