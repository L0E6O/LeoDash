#include "mainwindow.h"

#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    bool terminator = false;
    while(!terminator){
        w.show();
        w.scriviNum();
        std::cout<<"hello world"<<std::endl;
    }
    return a.exec();
}
