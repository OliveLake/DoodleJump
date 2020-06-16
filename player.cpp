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


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap PlayerPixmap(":/new/prefix1/image/pngwing.com.png");
    QPixmap pic(QPixmap(PlayerPixmap).scaled(OBJ_SIZE, OBJ_SIZE, Qt::IgnoreAspectRatio,Qt::FastTransformation));
    setPixmap(pic);

    count = 0;
    state = 2;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(JUMPRATE);

          //  qDebug()<<state;

  //  QMediaPlayer * music = new QMediaPlayer();


}
void Player::ChangeCloth()
{
    QPixmap PlayerPixmap(":/new/prefix1/image/player2.png");
    QPixmap pic(QPixmap(PlayerPixmap).scaled(OBJ_SIZE, OBJ_SIZE, Qt::IgnoreAspectRatio,Qt::FastTransformation));
    setPixmap(pic);
}
void Player::iniScore()
{
    score = new Score();
    score->setPos(GAME_WIDTH-100,0);
    scene()->addItem(score);
    gameover = new Gameover();
    gameover->setPos(GAME_WIDTH/3-50,GAME_HEIGHT/3);
    scene()->addItem(gameover);
    gameover->hide();
}

//用火箭的時候自動跳躍要暫停
void Player::move()
{
    if(score->getScore()>100)  ChangeCloth();
    if(y()>GAME_HEIGHT)
    {
        //暫停
        gameover->show();
    }
    //鑑測鍵盤狀態
    if(y()<200)
    {
        JUMPHIGH = 1;
        dy = 300-y();
       // qDebug()<<"dy"<<dy;
        for(int i = 0;i<10;i++)
        {
            p[i]->setY(p[i]->y()+JUMPHIGH);
            CollidingRect[i]->setY(CollidingRect[i]->y()+JUMPHIGH);

        }
        setY(y()+JUMPHIGH);
        qDebug()<<y();
      //  return 1;
    }





    JumpColliding();

    switch (state)
    {
        case 1:
        {
           // checkposition = CheckPosition();
            JUMPHIGH = 5;//速度
           // qDebug()<<"state 1";
            if(count<=40 && state==1 )   //up
            {
               //if(CheckPosition())    qDebug()<<"dowm";
                setPos(x(),y()-JUMPHIGH);
                count++;
                for(int i = 0;i<10;i++)
                {
                    pX = p[i]->position();
                    score->increase(pX);
                 //  qDebug()<<p[i]->position();
                    CollidingRect[i]->position(pX);
                }
            }
           if(count==40) state = 2;

           break;
        }

        case 2:
        {
            JUMPHIGH = 5;//速度
            setPos(x(),y()+JUMPHIGH);
            break;
        }
    }
}
bool Player::CheckPosition()
{   /*
    if(y()<200)
    {
        JUMPHIGH = 1;
        dy = 300-y();
       // qDebug()<<"dy"<<dy;
        for(int i = 0;i<10;i++)
        {
            p[i]->setY(p[i]->y()+JUMPHIGH);
            CollidingRect[i]->setY(CollidingRect[i]->y()+JUMPHIGH);

        }
        setY(y()+JUMPHIGH);
      //  qDebug()<<y();
      //  return 1;
    }
    return 0;
*/
}
void Player::JumpColliding()
{
     QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
            if (typeid(*(colliding_items[i])) == typeid(Transparent) && state==2)  //down
            {
                //qDebug()<<"coll";
                count = 0;
                state = 1;
                QMediaPlayer * music = new QMediaPlayer();
         //       music->setMedia(QUrl(":/sound/image/jumpSound.mp3"));
                music->setMedia(QUrl::fromLocalFile("/Users/User/Desktop/C++/2020-pd2-doodlejump/image/jumpSound.mp3"));
                music->play();
                music->setVolume(100);/*
                if (music->state() == QMediaPlayer::PlayingState)
                {
                      music->setPosition(0);
                }
                else if (music->state() == QMediaPlayer::StoppedState)
                {
                    qDebug()<<"play";
                      music->play();
                }*//*
                QSoundEffect *sound;
                sound = new QSoundEffect(this);
                sound->setSource( QUrl(":/sound/image/jumpSound.mp3") );
                sound->setVolume(100);
                sound->play();
                */
               // music->play();
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


