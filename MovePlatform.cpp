#include "MovePlatform.h"
#include "Platform.h"
#include "Constants.h"
#include <QDebug>

MovePlatform::MovePlatform(QGraphicsItem *parent): Platform()
{
        setPixmap(QPixmap(":/new/prefix1/image/blue_platforms.png"));

}
void MovePlatform::position()
{
      //  setPos(x(),y()-3);
}
