#include "Transparent.h"
#include <QGraphicsScene>

Transparent::Transparent(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    setRect(0,0,80,1);

}
