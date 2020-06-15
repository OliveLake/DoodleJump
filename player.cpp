#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "Bullet.h"
#include "Platform.h"
#include "Transparent.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap PlayerPixmap(":/new/prefix1/image/pngwing.com.png");
 //   PlayerPixmap.scaled(QSize(OBJ_SIZE,OBJ_SIZE),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    qDebug()<<"playerset";
//    setOffset(p_x,p_y);
//    QPixmap scaled = PlayerPixmap.scaled(QSize(10, 10));
//    QPainter painter(this);
//    painter.drawPixmap(0, 0, scaled)
 //   QBrush brush(PlayerPixmap.scaled(2, 2, Qt::IgnoreAspectRatio,
 //                           Qt::FastTransformation));
    QPixmap pic(QPixmap(PlayerPixmap).scaled(OBJ_SIZE, OBJ_SIZE, Qt::IgnoreAspectRatio,Qt::FastTransformation));
    setPixmap(pic);

//    colliding_items = collidingItems();

    JUMPHIGH = 5;
    count = 0;
    state = 1;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(JUMPRATE);

          //  qDebug()<<state;



}

//用火箭的時候自動跳躍要暫停
void Player::move()
{
  //  qDebug()<<state;
    JumpColliding();
    switch (state)
    {
        case 1:
        {
           // qDebug()<<"state 1";
            if(count<=40 && state==1)   //up
            {
                setPos(x(),y()-JUMPHIGH);
                count++;
            }
           if(count==40) state = 2;
           break;
        }

        case 2:
        {
            setPos(x(),y()+JUMPHIGH);

            break;
        }
    }
}
void Player::JumpColliding()
{
     QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
            if (typeid(*(colliding_items[i])) == typeid(Transparent) && state==2)  //down
            {
                qDebug()<<"coll";
                count = 0;
                state = 1;
                //碰撞到板子 count=0 上升碰到平台return
              //  AutoJump();
          //      JUMPHIGH = 0;

             //   jump();
             //   timer->stop();

            }
            //switch ()
    }



}


void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-30,y());
        if (pos().x() <= 0)
        setPos(GAME_WIDTH,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+30,y());
        if (pos().x() > GAME_WIDTH)
            setPos(0,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void Player::spawn(){
    // create an enemy
    Platform * platform = new Platform();
    scene()->addItem(platform);
}

Platform* Player::iniPlatform(int x,int y)  //  改回傳值
{
    Platform * platform = new Platform();
  //  p[0] = new Platform()
    platform->setPos(x,y);
    scene()->addItem(platform); //把平台存在陣列   a[0].y();
    return platform;
}

Transparent* Player::iniCollingRect(int x, int y)
{
    Transparent* collidingrect = new Transparent();
    collidingrect->setPos(x,y);
    scene()->addItem(collidingrect);
    return collidingrect;
}

