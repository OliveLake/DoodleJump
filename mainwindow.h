#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void InitialScene();
    void Shoot();
    ~MainWindow();


private:
 //   Ui::MainWindow *ui;
    QPixmap BackgroundPixmap_1;
    QPixmap BackgroundPixmap_2;
    QPixmap Player;

    int p_x;
    int p_y;
};

#endif // MAINWINDOW_H
