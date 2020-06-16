#include "mainwindow.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
#include <QImage>
#include <QDebug>
#include <QThread>

//bonus
//反轉圖片
//射子彈圖片反轉
//done
//可穿牆


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,view(new QGraphicsView(this))
    ,scene(new QGraphicsScene(this))
    , BackgroundPixmap(":/new/prefix1/image/temp1406589445.png")
{


    Btn=new QPushButton(QString("Pause"),this);
    connect(Btn,SIGNAL(clicked()),this,SLOT(onBnClicked()));

    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/image/temp1406589445.png")));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    resize(GAME_WIDTH,GAME_HEIGHT);

    view->setSceneRect(0,0,GAME_WIDTH,GAME_HEIGHT); //讓視窗固定// make the scene 800x600 instead of infinity by infinity (default)
   view->setFixedSize(GAME_WIDTH,GAME_HEIGHT);




    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    view->setScene(scene);

    // create the player
    p_x = GAME_WIDTH*0.5; p_y = GAME_HEIGHT*0.7;
    player = new Player();
    player->setPos(p_x,p_y); // TODO generalize to always be in the middle bottom of screen
    //qDebug()<<y();
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);



    player->iniScore();
    // create the score/health
/*    score = new Score();
    scene->addItem(score);
    score->setPos(GAME_WIDTH-100,0);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
*/

    int High = 700;
    int RandomWidth = rand() % GAME_WIDTH-50;
    for(int i = 0;i<10;i++)
    {

        player->p[i] = player->iniPlatform(RandomWidth,High) ;
  //      qDebug()<<player->p[i]->x()<<player->p[i]->y();
        player->CollidingRect[i] = player->iniCollingRect(player->p[i]->x()+60,player->p[i]->y()+20);
        High -=70;
        RandomWidth = rand() % GAME_WIDTH-50;

            qDebug()<<player->p[i]->x()<<player->p[i]->y();
            qDebug()<<player->CollidingRect[i]->x()<<player->CollidingRect[i]->y();
    }
    for(int i = 0;i<2;i++)
    {
        player->s[i] = player->iniSpring(player->CollidingRect[i+6]->x(),player->CollidingRect[i+6]->y()-30);
        qDebug()<<"spring"<< player->s[i]->x()<<player->s[i]->y();

    }


 //   view->show();


}



void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

}


void MainWindow::onBnClicked()
{
   // QThread::sleep(10000000);
    qDebug()<<"sleep";
    setFocus();
}










