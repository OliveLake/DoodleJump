#ifndef TRANSPARENT_H
#define TRANSPARENT_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>


class Transparent: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Transparent(QGraphicsItem * parent=0);
    void position();
    int dy;
    int randomX;
};

#endif // TRANSPARENT_H
