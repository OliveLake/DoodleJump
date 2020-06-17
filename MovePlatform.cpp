#include "MovePlatform.h"
#include "Platform.h"
#include <QDebug>
MovePlatform::MovePlatform(QGraphicsItem *parent): Platform()
{
        setPixmap(QPixmap(":/new/prefix1/image/blue_platforms.png"));
}
void MovePlatform::position()
{
        qDebug()<<"override";
}
