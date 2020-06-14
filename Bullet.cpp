#include "Bullet.h"
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

}

void Bullet::move()
{
    // move up
    setPos(x(),y()-10);
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"bullet deleted";
    }
}
    //先做collidingitem   //腳站在板子才行
    //板子不重疊
    //背景滾動
    //兩種板子->繼承
    //道具：彈簧、火箭
    //怪物射死ok
    //黑洞
    //暫停
    //分數
    //結束
