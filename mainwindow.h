#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QTimer>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "player.h"



//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
//    void InitialScene();
//    void GamePlay();
//    void Shoot();
//    void UpdatePos();
//    void PlayerPos();
 //   QTimer   m_Timer;


private:
 //   Ui::MainWindow *ui;
    QPixmap BackgroundPixmap;
 //   QPixmap BackgroundPixmap_2;
    QPixmap PlayerPixmap;
//    QGraphicsItem *Player;
  //  QRect p_rect;


    QGraphicsScene *scene;
    QGraphicsView *view;
//    Player *player;

//    QGraphicsPixmapItem *item;

    int p_x;
    int p_y;

};

#endif // MAINWINDOW_H
