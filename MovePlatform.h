#ifndef MOVEPLATFORM_H
#define MOVEPLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Platform.h"

class MovePlatform: public Platform{
public:
    MovePlatform(QGraphicsItem * parent=0);
    void position() override;
//public slots:
 //   void position();
};



#endif // MOVEPLATFORM_H
