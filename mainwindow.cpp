#include "mainwindow.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
#include <QImage>
#include <QDebug>

//bonus
//反轉圖片
//射子彈圖片反轉
//done
//可穿牆


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,view(new QGraphicsView(this))
    ,scene(new QGraphicsScene(this))
  //  view(new QGraphicsView(scene, this))
   // , scene(new QGraphicsScene())
  //  , view(new QGraphicsView(scene))
    , BackgroundPixmap(":/new/prefix1/image/temp1406589445.png")


{
  //  item = QGraphicsPixmapItem(QPixmap(":/new/prefix1/image/temp1406589445.png"));

    // create the scene
   // view = new QGraphicsView();
  //  scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/image/temp1406589445.png")));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    resize(GAME_WIDTH,GAME_HEIGHT);

    view->setSceneRect(0,0,GAME_WIDTH,GAME_HEIGHT); //讓視窗固定// make the scene 800x600 instead of infinity by infinity (default)
   view->setFixedSize(GAME_WIDTH,GAME_HEIGHT);




    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    view->setScene(scene);
//    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

 //   view->setScene(scene);

 //   scene->addPixmap(BackgroundPixmap);

    // create the player
    p_x = GAME_WIDTH*0.5; p_y = GAME_HEIGHT*0.5;
    player = new Player();
    player->setPos(p_x,p_y); // TODO generalize to always be in the middle bottom of screen
    qDebug()<<y();
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);


 //   scene->addRect(0,0,50,50);

    // create the score/health
/*    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
*/
    // spawn enemies
//    QTimer * timer = new QTimer();
//    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
//    timer->start(0);

    for(int i = 0;i<6;i++)
        player->iniPlatform();

 //   view->show();


}



void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
  //   QPainter painter_2(this);
 //   painter.drawPixmap(0,0,GAME_WIDTH,GAME_HEIGHT,BackgroundPixmap);
 //   painter.drawPixmap(this->rect(),BackgroundPixmap_2);
 //   PlayerPixmap=PlayerPixmap.scaled(OBJ_SIZE,OBJ_SIZE,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
 //   painter.drawPixmap(p_x,p_y,PlayerPixmap);
    // rec
}














/*
#include "player.h"

#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
//#include <QPainterPath>
//#include <QImage>


#define JUMPHIGH    100
#define OBJ_SIZE    50
#define GAME_WIDTH  500
#define GAME_HEIGHT 700
#define GAME_TITLE "Doodle JuJuJump"
#define GAME_RATE  10




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , BackgroundPixmap(":/new/prefix1/image/temp1406589445.png")
    , PlayerPixmap(":/new/prefix1/image/pngwing.com.png")
    , scene(new QGraphicsScene())
    , view(new QGraphicsView(scene))
//    , player(new Player(*this))


{
    p_x = GAME_WIDTH/2;
    p_y = GAME_HEIGHT*0.8;

    //set scene
     resize(GAME_WIDTH,GAME_HEIGHT);
 //   setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    scene->addPixmap(BackgroundPixmap);

    //set player
   // item = new QGraphicsItem();
 //   QGraphicsItem *item = new QGraphicsItem();


    scene->addPixmap(PlayerPixmap);


//    player = new Player();


  //  Player->setPixmap(QPixmap(":/images/player.png"));

   // ad(QPixmap(":/images/player.png"));
 //   QImage *JBackground = new QImage(":/new/prefix1/image/temp1406589445.png");
 //   QImage Background = JBackground->scaled(GAME_WIDTH,GAME_HEIGHT,Qt::KeepAspectRatio);
 //    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/image/temp1406589445.png")));
 //    scene->setSceneRect(100,0,GAME_WIDTH,GAME_HEIGHT);

     view->setScene(scene);


  //  QPixmap BackgroundPixmap(":/new/prefix1/image/temp1406589445.png");

}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
  //   QPainter painter_2(this);
    painter.drawPixmap(0,0,GAME_WIDTH,GAME_HEIGHT,BackgroundPixmap);
 //   painter.drawPixmap(this->rect(),BackgroundPixmap_2);
    PlayerPixmap=PlayerPixmap.scaled(OBJ_SIZE,OBJ_SIZE,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    painter.drawPixmap(p_x,p_y,PlayerPixmap);
    // rec
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
      //Player->setPos(0,0);
    }
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
 //   , ui(new Ui::MainWindow)
    , BackgroundPixmap_1(":/new/prefix1/image/temp1406589445.png")
    , BackgroundPixmap_2(":/new/prefix1/image/temp1406589445.png")
    , Player(":/new/prefix1/image/pngwing.com.png")



{
   // ui->setupUi(this);

    InitialScene();
    GamePlay();
    UpdatePos();
}

MainWindow::~MainWindow()
{

 //   delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
  //   QPainter painter_2(this);
    painter.drawPixmap(this->rect(),BackgroundPixmap_1);
    painter.drawPixmap(this->rect(),BackgroundPixmap_2);
    Player=Player.scaled(OBJ_SIZE,OBJ_SIZE,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    painter.drawPixmap(p_x,p_y,Player);
    //initial rec




}

void MainWindow::InitialScene()
{
//    MainWindow::PaintEvent(&BackgroundPixmap);

    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    p_x = GAME_WIDTH/2;
    p_y = GAME_HEIGHT*0.8;

    //rect of player
    p_rect.setWidth(Player.width());
    p_rect.setHeight(Player.height());
    Player.moveTo(p_x,p_y);




}

void MainWindow::GamePlay()
{
  //  QTimer p_timer = new QTimer(); why not:p_timer = new QTimer(this)
  //   p_timer.setInterval(GAME_RATE);
    QTimer *p_timer = new QTimer(this);
    p_timer->setInterval(10);
    connect(p_timer,&QTimer::timeout,[=](){

        UpdatePos();

       });
 //  connect(timer, SIGNAL(timeout()), this, SLOT(update()));    //SIGNAL(timeout()):每当计时结束，计时器归零并重新计时，并发送一个信号激活slot函数。
 //   timer->start(1000); //每次timeout的时间间隔是1000ms

}

void MainWindow::UpdatePos()
{
    qDebug()<<p_y;
    p_y += JUMPHIGH;
    qDebug()<<p_y;
    this->repaint();
    moveBy(p_x,p_y);
    p_y -= JUMPHIGH;
    qDebug()<<p_y;

    p_rect.moveTo(p_x,p_y);


}


void MainWindow::Shoot()
{

}
*/
