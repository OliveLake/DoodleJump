#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#define GAME_WIDTH  500
#define GAME_HEIGHT 700
#define GAME_TITLE "Doodle JuJuJump"


//QGraphicsScene scene;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
 //   , ui(new Ui::MainWindow)
    , BackgroundPixmap_1(":/new/prefix1/image/temp1406589445.png")
    , BackgroundPixmap_2(":/new/prefix1/image/temp1406589445.png")
    , Player(":/new/prefix1/image/pngwing.com.png")


{
   // ui->setupUi(this);
  //  BackgroundPixmap=BackgroundPixmap.scaled(400,400);

    InitialScene();
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

}

void MainWindow::InitialScene()
{
//    MainWindow::PaintEvent(&BackgroundPixmap);
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);

}
