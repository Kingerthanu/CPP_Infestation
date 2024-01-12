#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <filesystem>
#include <iostream>
#include <cstring>
#include <bird.h>
#include <QTimer>
#include <Swap.h>
#include <QLabel>
#include <QVBoxLayout>
#include <Qt>
#include <QPalette>
#include <random>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    std::cout << (a.applicationDirPath().toStdString().substr(0, (a.applicationDirPath().toStdString().size() - 61)) + "Infestation/imgs/Stock.jpg") + "\n";
    std::cout << "LENGTH: " << w.width() << " " << w.height();
    w.show();
    w.setWindowTitle("Infestation");
    QPixmap img((a.applicationDirPath().toStdString().substr(0, (a.applicationDirPath().toStdString().size() - 61)) + "Infestation/imgs/Stock.jpg").c_str());
    w.setWindowIcon(img);
    return a.exec();
}
