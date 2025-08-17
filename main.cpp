#include "mainwindow.h"
#include "datagatherer.h"
#include <unistd.h>
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DataGatherer dG;
    bool terminator = false;
    int16_t datiRaw[6];
    float dati[6];
    while(!terminator){
        dG.prendiDati(datiRaw);
        for(int i = 0; i < 3; i++){
            dati[i] = datiRaw[i] / 16384.0f;
        }
        w.show();
        w.scriviDati(dati);
        usleep(100000);
    }
    return a.exec();
}
