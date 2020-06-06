#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
//#include "Bullet.h"
//#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    p_x = GAME_WIDTH*0.5; p_y = GAME_HEIGHT*0.8;
    QPixmap PlayerPixmap(":/new/prefix1/image/pngwing.com.png");
    setPixmap(PlayerPixmap);
    qDebug()<<"playerset";
//    setOffset(p_x,p_y);
}



void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
 //       Bullet * bullet = new Bullet();
 //       bullet->setPos(x(),y());
 //       scene()->addItem(bullet);
    }
}

void Player::spawn(){
    // create an enemy
//    Enemy * enemy = new Enemy();
 //   scene()->addItem(enemy);
}
