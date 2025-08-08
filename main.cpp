#include "mainwindow.h"

#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int num = rand() % 101;
    w.scriviNum(num);
    std::cout<<"hello world"<<std::endl;
    return a.exec();
}
