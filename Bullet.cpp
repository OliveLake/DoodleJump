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
    //板子不重疊 //整個視窗的座標
    //背景滾動
    //兩種板子->繼承  //板子掉下 圖片分成兩個
    //道具：彈簧、火箭  //移動怪怪的       //火箭會快速上升，autojump暫停 時間要暫停嗎
    //怪物射死ok
    //黑洞
    //暫停
    //分數
    //結束        //有一個視窗是gameover

    //換裝
    //音效
    //
