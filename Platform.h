#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Transparent.h"

class Platform: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Platform(QGraphicsItem * parent=0);
    int dy;
    int randomX;
    Transparent* Col;

public slots:
    void position();
};


#endif // PLATFORM_H
