#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QPushButton>

#include <QGraphicsPixmapItem>

#include "Constants.h"
#include "player.h"
#include "Platform.h"
#include "Transparent.h"
#include "Score.h"
//#include "Health.h"

class MainWindow:public QMainWindow
{
public:
    MainWindow(QWidget * parent=0);
    void paintEvent(QPaintEvent *);
    Score * score;
    Gameover* gameover;
public slots:
    void AutoJump(int if_jump);
    void onBnClicked();
    void onPnClicked();

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    Player * player;
//    Score * score;
 //   Health * health;

    QPixmap BackgroundPixmap;
    QGraphicsPixmapItem item;

    QPushButton *Btn;
    QPushButton *Ptn;
    int p_x;
    int p_y;

//    Platform* p[12];
//    Transparent* CollidingRect[12];

};

#endif // GAME_H
