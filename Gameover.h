#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Gameover: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Gameover(QGraphicsItem * parent=0);

};

#endif // GAMEOVER_H
