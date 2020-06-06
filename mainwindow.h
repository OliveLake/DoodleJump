#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "Constants.h"
#include "player.h"
//#include "Score.h"
//#include "Health.h"

class MainWindow: public QMainWindow
{
public:
    MainWindow(QWidget * parent=0);
    void paintEvent(QPaintEvent *);

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    Player * player;
 //   Score * score;
 //   Health * health;

    QPixmap BackgroundPixmap;

};

#endif // GAME_H
