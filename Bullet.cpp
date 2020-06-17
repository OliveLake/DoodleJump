#include "Bullet.h"
#include "Monster.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>


Bullet::Bullet(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap BulletPixmap(":/new/prefix1/image/pngwing.bullet.png");
    QPixmap pic(QPixmap(BulletPixmap).scaled(10,10, Qt::IgnoreAspectRatio,Qt::FastTransformation));
    setPixmap(pic);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    Monster * mon = new Monster();
}

void Bullet::move()
{
    collid();
    // move up
    setPos(x(),y()-10);
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"bullet deleted";
    }
}
void Bullet::collid()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
   for (int i = 0, n = colliding_items.size(); i < n; ++i)
   {
           if (typeid(*(colliding_items[i])) == typeid(Monster) )  //down
           {
               //qDebug()<<"mon";
                mon->hide();
           }
           //switch ()
   }
}
