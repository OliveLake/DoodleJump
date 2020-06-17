#include "Transparent.h"
#include "Constants.h"
//#include "Platform.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

Transparent::Transparent(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    setRect(0,0,40,1);
}

void Transparent::position()
{
    dy = 700-y();
    if(y()>700)
    {
//        setPos(sx+60,dy);
//        qDebug()<<"line:"<<x()<<y();
 //       qDebug()<<sx;
    }
}
/*
 QImage image(":/Images/logo");
QImage mirroredImage = image.mirrored(false, false);
QPixmap pixmap = QPixmap::fromImage(mirroredImage);
*/
