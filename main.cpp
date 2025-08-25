#include "mainwindow.h"
#include "datagatherer.h"
#include <unistd.h>
#include <QApplication>
#include <QTimer>
#include <thread>
#include <mutex>
#include "./server/api.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DataGatherer dG;
    api api;
    bool terminator = false;
    int16_t datiRaw[6];
    float dati[6];
    std::mutex mtx;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();

    std::thread serverThread([&api, &dati, &mtx]() {
        api.apiServerStartup(dati, &mtx);
    });

    serverThread.detach();

    QTimer timer; //un timer
    QObject::connect(&timer, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        int16_t datiRaw[6];
        dG.prendiDati(datiRaw);
        mtx.lock();
        for (int i = 0; i < 3; i++) {
            dati[i] = datiRaw[i] / 1638.4f;
        }
        for (int i = 3; i < 6; i++){
            dati[i] = datiRaw[i] / 131.0;
        }
        w.scriviDati(dati);
        mtx.unlock();
    });

    timer.start(200); // ogni 100 ms (come usleep(100000))
    return a.exec();
}
