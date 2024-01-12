#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bird.h>
#include <QGraphicsScene>
#include <QLabel>
#include <QPainter>
#include <bird.h>
#include <iostream>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsView>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    double DIRECTIONSL[3][2] = {{1,1}, {1, 0}, {-1,-1}};
    double DIRECTIONSR[3][2] = {{-1,0}, {-1, -1}, {1,1}};
    QPalette pal;
    bird *tmp;
    int tm = -1;
    std::default_random_engine rng = *new std::default_random_engine(time(0));
    int timerId;
    QGraphicsScene layout = new QGraphicsScene(this);
    QGraphicsView *view = new QGraphicsView(this);
    QLabel *score = new QLabel("Score: ", this);
    QLabel *scoreN = new QLabel("0", this);
    std::uniform_int_distribution<std::mt19937::result_type> distX = *new std::uniform_int_distribution<std::mt19937::result_type>(0,1);
    std::uniform_int_distribution<std::mt19937::result_type> distD = *new std::uniform_int_distribution<std::mt19937::result_type>(0,2);
    std::uniform_int_distribution<std::mt19937::result_type> distY = *new std::uniform_int_distribution<std::mt19937::result_type>(0,670);

private:
    Ui::MainWindow *ui;
protected:
    void timerEvent(QTimerEvent *event);
};
#endif // MAINWINDOW_H
