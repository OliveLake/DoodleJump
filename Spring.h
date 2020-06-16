#ifndef SPRING_H
#define SPRING_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Spring: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spring(QGraphicsItem * parent=0);
public slots:

};


#endif // SPRING_H
