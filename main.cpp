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
    int16_t datiRaw[6]; //array per salare i dati grezzi
    float dati[6]; //array per salvare i dati in deciG
    std::mutex mtx; //oggetto mutex per mutua esclusione
    w.setWindowState(Qt::WindowFullScreen); //metto la finestra a schermo intero
    w.show();

    std::thread serverThread([&api, &dati, &mtx]() { //creo un oggetto thread dove lancio l'API
        api.apiServerStartup(dati, &mtx);
    });

    serverThread.detach(); //lancio il thread sopra creato, staccando dall'esecuzione di main

    QTimer timer; //un timer
    QObject::connect(&timer, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        int16_t datiRaw[6];
        dG.prendiDati(datiRaw); //prendo i dati dal sensore
        mtx.lock(); //attivo la mutua esclusione, bloccando tutti gli altri thread, in modo da avere l'accesso esclusivo alle variabili
        for (int i = 0; i < 3; i++) {
            dati[i] = datiRaw[i] / 1638.4f; //converto in g
        }
        for (int i = 3; i < 6; i++){
            dati[i] = datiRaw[i] / 131.0; //converto in ... boh, mel'ha detto chat
        }
        w.scriviDati(dati); //scrivo dati sulla GUI
        mtx.unlock(); //sblocco gli altri thread, forse potrei farlo poco prima
    });

    timer.start(200); // ogni 100 ms (come usleep(100000))
    return a.exec();
}
