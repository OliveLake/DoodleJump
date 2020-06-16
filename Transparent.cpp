#include "Transparent.h"
#include "Constants.h"
#include "Platform.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

Transparent::Transparent(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    setRect(0,0,40,1);
}

void Transparent::position(int sx)
{
    dy = y()-700;
    if(y()>720)
    {
        setPos(sx+60,dy);
        qDebug()<<"line:"<<x()<<y();

    }



}
