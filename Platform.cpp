#include "Platform.h"
#include "Constants.h"
#include "player.h"
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

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(position()));

    timer->start(JUMPRATE);

}

int Platform::position()
{
    qsrand(time(NULL));
    dy = y()-700;
    if(y()>700)
    {

        randomX = rand() % GAME_WIDTH;
        while(randomX<-20 || randomX > 350)
           randomX = rand() % GAME_WIDTH;
        setPos(randomX,dy);
        qDebug()<<randomX<<"plat:"<<x()<<y();
        return randomX;

    }

    return 0;

}
//移動的函數 每一次都要確定最後y是否低於底部
