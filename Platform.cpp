#include "Platform.h"
#include "Constants.h"
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QDebug>

Platform::Platform(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    int RandomHeight = rand() % GAME_HEIGHT;
    int RandomWidth = rand() % GAME_WIDTH-50;


    qDebug()<<RandomWidth<<RandomHeight;
    setPos(RandomWidth,RandomHeight);

    setPixmap(QPixmap(":/new/prefix1/image/platforms_green.png"));

   // QTimer * timer = new QTimer(this);
   // connect(timer,SIGNAL(timeout()),this,SLOT(move()));

   // timer->start(50);

}
