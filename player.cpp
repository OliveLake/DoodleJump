#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QSoundEffect>
#include "player.h"
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
    state = 2;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(JUMPRATE);

          //  qDebug()<<state;

  //  QMediaPlayer * music = new QMediaPlayer();




}

//用火箭的時候自動跳躍要暫停
void Player::move()
{
    if(y()<200)  //while裡面一個for?
    {
        dy = 300-y();
        qDebug()<<"dy"<<dy;
        for(int i = 0;i<10;i++)
        {
            for(int j = 0;j<5;j++)
            {

                p[i]->setY(p[i]->y()+JUMPHIGH);
                CollidingRect[i]->setY(CollidingRect[i]->y()+JUMPHIGH);
                setY(y()+JUMPHIGH);
              //  qDebug()<<y();
            }
            if(CollidingRect[i]->y()>GAME_HEIGHT)
            {
                int High = 700;
                int RandomWidth = rand() % GAME_WIDTH-50;
            }
        }

    }
    if(y()>500)
    {

    }

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
                //qDebug()<<"coll";
                count = 0;
                state = 1;
/*                QMediaPlayer * music = new QMediaPlayer();
                music->setMedia(QUrl(":/sound/image/jumpSound.mp3"));
                music->setVolume(1000);
                if (music->state() == QMediaPlayer::PlayingState)
                {
                      music->setPosition(0);
                }
                else if (music->state() == QMediaPlayer::StoppedState)
                {
                    qDebug()<<"play";
                      music->play();
                }*/
                QSoundEffect *sound;
                sound = new QSoundEffect(this);
                sound->setSource( QUrl(":/sound/image/jumpSound.mp3") );
                sound->setVolume(10000);
                sound->play();
               // music->play();
                //碰撞到板子 count=0 上升碰到平台return
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

