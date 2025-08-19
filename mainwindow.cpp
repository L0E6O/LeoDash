#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>

 QTimer timerX; //un timer
 QTimer timerY; //un timer

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scriviDati(float dati[]){
    QObject::connect(&timerX, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        ui->lAX->setStyleSheet({"#lAX {background-color: white;}"});
    });
    QObject::connect(&timerY, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        ui->lAY->setStyleSheet({"#lAY {background-color: white;}"});
    });

    if(dati[0] > 7){
        ui->lAX->setStyleSheet({"#lAX {background-color: red;}"});
        timerX.start(2000);
    }
    if(dati[1] > 7){
        ui->lAY->setStyleSheet({"#lAY {background-color: red;}"});
        timerY.start(2000);
    }
    ui->lAX->setText("accX" + QString::number(dati[0], 'f', 2));
    ui->lAY->setText("accY" + QString::number(dati[1], 'f', 2));
}
