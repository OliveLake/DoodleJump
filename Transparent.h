#ifndef TRANSPARENT_H
#define TRANSPARENT_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Transparent: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Transparent(QGraphicsItem * parent=0);
};

#endif // TRANSPARENT_H
