#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(QSize(800,800));
    view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->statusBar()->hide();
    score->setStyleSheet("font-size: 25px; color: white;");
    scoreN->setStyleSheet("font-size: 25px; color: white;");
    score->setGeometry(0,-35,100,100);
    scoreN->setGeometry(75,-35,100,100);
    for(int i = 0; i <  5; i++){
        int r = distX(rng);
        if (r == 0){
        tmp = new bird(distX(rng), distY(rng), DIRECTIONSL[distD(rng)]);
        }
        else{
        tmp = new bird(distX(rng), distY(rng), DIRECTIONSR[distD(rng)]);
        }
        layout.addItem(tmp);
    }
    layout.setSceneRect(0,0,800,800);
    timerId = startTimer(10);
    // setup signal and slot
    view->setGeometry(0,0, 800,800);
    view->setScene(&layout);
    setCentralWidget(view);
    this->centralWidget()->setStyleSheet("background-image: url('C:/Users/Daddy/Desktop/The Code Box/CPP Docs/first cpp/Gui/Infestation/imgs/bgO.png'); background-position: center;");
}
void MainWindow::paintEvent(QPaintEvent *event){
    if(tm > layout.items().size()){
    char buffer[50];
    sprintf(buffer, "%d", scoreN->text().toInt() + 1);
    scoreN->setText(buffer);
    layout.addItem(new bird(distX(rng), distY(rng), DIRECTIONSL[distD(rng)]));
    }
    tm = layout.items().size();
}
void MainWindow::timerEvent(QTimerEvent *event){
    for(QGraphicsItem *each : layout.items()){
        each->moveBy(each->data(77).toDouble(), each->data(66).toDouble());
        if(each->x() < -20 || each->y() < -20 || each->x() > 400 || each->y() > 400){
            if(each->data(78) == 1){
                delete each;
                break;
            }
            each->setPos(distX(rng)*399, distY(rng));
        }
    }
    this->update();
}
MainWindow::~MainWindow()
{
    killTimer(timerId);
    delete ui;
}

