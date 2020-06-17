#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QSoundEffect>
#include "player.h"
#include "Bullet.h"
#include "Platform.h"
#include "Spring.h"
#include "Transparent.h"
#include "Gameover.h"
#include "MovePlatform.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap PlayerPixmap(":/new/prefix1/image/pngwing.com.png");
    QPixmap pic(QPixmap(PlayerPixmap).scaled(OBJ_SIZE, OBJ_SIZE, Qt::IgnoreAspectRatio,Qt::FastTransformation));
    setPixmap(pic);

    state = 2;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(JUMPRATE);
    Platform * movePlat = new MovePlatform();
    movePlat->setPos(200,200);
    scene()->addItem(movePlat);
}
void Player::ChangeCloth()
{
    QPixmap PlayerPixmap(":/new/prefix1/image/player2.png");
    QPixmap pic(QPixmap(PlayerPixmap).scaled(OBJ_SIZE, OBJ_SIZE, Qt::IgnoreAspectRatio,Qt::FastTransformation));
    setPixmap(pic);
}

void Player::iniScore()
{
    monster = new Monster();
    monster->setPos(200,200);
    scene()->addItem(monster);
    /*
    score = new Score();
    score->setPos(GAME_WIDTH-100,0);
    scene()->addItem(score);
    gameover = new Gameover();
    gameover->setPos(GAME_WIDTH/3-50,GAME_HEIGHT/3);
    scene()->addItem(gameover);
    gameover->hide();
*/
}

void Player::move()
{
    if(!isStop)
    {
        dy = y();
        if(dy<=GAME_HEIGHT*0.3)     cameraSpeed = 3;
        else if(dy<=GAME_HEIGHT*0.2)    cameraSpeed = 5;
        else if(dy<=GAME_HEIGHT*0.1)    cameraSpeed = 6;
        else if(dy<=GAME_HEIGHT*0.05)   cameraSpeed= 7;
        else    cameraSpeed = 0;

        checkMove();
        JumpColliding();

        switch (state)
        {
            case 1:
            {
                if(playerCount<=40 && state==1 )   //up
                {
                    setPos(x(),y()-playerSpeed);
                    playerCount++;
                }
               if(playerCount==40) state = 2;
               break;
            }
            case 2:
            {
                setPos(x(),y()+playerSpeed);
                break;
            }
        }

        if(score->getScore()>3000)  ChangeCloth();
        if(y()>GAME_HEIGHT)
        {
            gameover->show();
            isStop = true;
           // score->setPos(GAME_WIDTH/3-50,GAME_HEIGHT/3);
        }
     }
}
void Player::checkMove()
{
        for(int i = 0;i<10;i++)
        {
            p[i]->setY(p[i]->y()+cameraSpeed);
          //  qDebug()<<"plat"<<p[i]->y();
            p[i]->Col->setY(p[i]->y()+cameraSpeed+20);
   //         qDebug()<<"rect"<<p[i]->CollidingRect->y();
            p[i]->position();
       //     p[i]->CollidingRect->position();
            score->increase();
         //   qDebug()<<"pX"<<pX;
        //    CollidingRect[i]->position(pX);
 //          if(i == 4 )   s[0]->position(pX);
 //           if(i == 9 )   s[1]->position(pX);
        }
        setY(y()+cameraSpeed);
}
void Player::JumpColliding()
{
     QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
            if (typeid(*(colliding_items[i])) == typeid(Transparent) && state==2)  //down
            {
                playerCount = 0;
                state = 1;
                QMediaPlayer * music = new QMediaPlayer();
                //music->setMedia(QUrl::fromLocalFile("/Users/User/Desktop/C++/2020-pd2-doodlejump/image/jumpSound.mp3"));
                music->setMedia(QUrl("/sound/image/jumpSound.mp3"));
                music->play();
                music->setVolume(100);
                //碰撞到板子 count=0 上升碰到平台return
            }
            //switch ()
    }
}


void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
  //  release_left = 1;
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-30,y());
        if (pos().x() <= 0)
            setPos(GAME_WIDTH,y());
        //press_left = 1;
    }
/*    if(press_left && release_left)
    {

        if (pos().x() > 0)
        setPos(x()-30,y());
        if (pos().x() <= 0)
        setPos(GAME_WIDTH,y());
    }*/
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
        bullet->mon = monster;
    }
}

/*void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        release_left = 0;
    }

}*/

void Player::spawn(){
    // create an enemy
    Platform * platform = new Platform();
    scene()->addItem(platform);
}

Spring* Player::iniSpring(int x,int y)
{
    Spring* spring = new Spring();
    spring->setPos(x,y);
    scene()->addItem(spring);
    return spring;
}

Platform* Player::iniPlatform(int x,int y)  //  改回傳值
{
    Platform * platform = new Platform();
    Transparent* CollidingRect = new Transparent();
  //  p[0] = new Platform()
    platform->setPos(x,y);
    scene()->addItem(platform); //把平台存在陣列   a[0].y();
    scene()->addItem(CollidingRect);
    platform->Col = CollidingRect;
    platform->Col->setPos(x+60,y+20);
    return platform;
}

Transparent* Player::iniCollingRect(int x, int y)
{
    Transparent* collidingrect = new Transparent();
    collidingrect->setPos(x,y);
    scene()->addItem(collidingrect);
    return collidingrect;
}


