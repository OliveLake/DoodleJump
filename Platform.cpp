#include "Platform.h"
#include "Constants.h"
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QDebug>

Platform::Platform(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{



    //另創一個clss coolidform 生成透明長方形 座標年在板子上 碰撞家在長方形 繼承platform 使用autojump

   // qDebug()<<RandomWidth<<RandomHeight;
   // setPos(RandomWidth,RandomHeight);

    setPixmap(QPixmap(":/new/prefix1/image/platforms_green.png"));

   // QTimer * timer = new QTimer(this);
   // connect(timer,SIGNAL(timeout()),this,SLOT(move()));

   // timer->start(50);

}
//移動的函數 每一次都要確定最後y是否低於底部
