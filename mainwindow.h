#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
//#include "Score.h"
//#include "Health.h"

class MainWindow: public QGraphicsView{
public:
    MainWindow(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
 //   Score * score;
 //   Health * health;

};

#endif // GAME_H
