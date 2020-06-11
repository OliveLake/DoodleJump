#include "Bullet.h"
#include <QTimer>


Bullet::Bullet(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap BulletPixmap(":/new/prefix1/image/pngwing.bullet.png");
    QPixmap pic(QPixmap(BulletPixmap).scaled(10,10, Qt::IgnoreAspectRatio,Qt::FastTransformation));
    setPixmap(pic);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void Bullet::move()
{
    // move up
    setPos(x(),y()-10);
}
