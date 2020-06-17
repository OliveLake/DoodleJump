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
void Spring::position(int sx)
{
    dy = y()-700;
    if(y()>500)
    {
        setPos(sx+60,dy);
  //      qDebug()<<"spring:"<<x()<<y();

    }
}
