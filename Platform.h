#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Platform: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Platform(QGraphicsItem * parent=0);
public slots:
  //  void move();
};


#endif // PLATFORM_H
