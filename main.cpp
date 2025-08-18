#include "mainwindow.h"
#include "datagatherer.h"
#include <unistd.h>
#include <QApplication>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DataGatherer dG;
    bool terminator = false;
    int16_t datiRaw[6];
    float dati[6];
    w.show();

    QTimer timer; //un timer
    QObject::connect(&timer, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        int16_t datiRaw[6];
        float dati[6];
        dG.prendiDati(datiRaw);
        for (int i = 0; i < 3; i++) {
            dati[i] = datiRaw[i] / 16384.0f;
        }
        w.scriviDati(dati);
    });

    timer.start(100); // ogni 100 ms (come usleep(100000))
    return a.exec();
}
