#include "Transparent.h"
#include "Constants.h"
#include "Platform.h"
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

 //   QTimer * timer = new QTimer(this);
 //   connect(timer,SIGNAL(timeout()),this,SLOT(position()));
  //  timer->start(JUMPRATE);
    Transparent* Col = new Transparent();
}

void Platform::position()
{   
    dy = y()-700;
    qsrand(time(NULL));
    if(y()>700)
    {
        randomX = rand() % GAME_WIDTH;
        while(randomX<-20 || randomX > 350)
           randomX = rand() % GAME_WIDTH;
        setPos(randomX,dy);
        Col->setPos(randomX+60,dy+20) ;
     //   qDebug()<<"plat:"<<x()<<y();
     //   qDebug()<<randomX;

     }


}
//移動的函數 每一次都要確定最後y是否低於底部
