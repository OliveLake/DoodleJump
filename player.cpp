#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "Bullet.h"
#include "Platform.h"

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

    count = 0;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(AutoJump()));
    timer->start(JUMPRATE);




}

//用火箭的時候自動跳躍要暫停

void Player::AutoJump()
{

   // qDebug()<<"Jump"<<count;
    if(count<=40)
    {
        setPos(x(),y()+JUMPHIGH);
        count++;
    }
    else if(count>40 && count<=80)
    {
        setPos(x(),y()-JUMPHIGH);
        count++;
    }
    if(count>80)    count = 1;

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

void Player::iniPlatform()
{
    Platform * platform = new Platform();
    scene()->addItem(platform);
}
