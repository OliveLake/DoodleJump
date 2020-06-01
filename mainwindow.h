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
    ~MainWindow();


private:
 //   Ui::MainWindow *ui;
    QPixmap BackgroundPixmap_1;
    QPixmap BackgroundPixmap_2;
};

#endif // MAINWINDOW_H
