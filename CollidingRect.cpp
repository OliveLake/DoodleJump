#include "CollidingRect.h"
#include "Constants.h"
#include "Platform.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

CollidingRect::CollidingRect(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    setRect(0,0,40,1);
}
