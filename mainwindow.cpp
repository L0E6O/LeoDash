#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QTimer>

 QTimer timer; //un timer

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
    QObject::connect(&timer, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        ui->lAX->setStyleSheet({"QLabel {background-color: white;}"});
    });
    if((dati[0] > 1) || (dati[1] > 1) || (dati[2] > 1)){
        ui->lAX->setStyleSheet({"QLabel {background-color: red;}"});
        timer.start(2000);
    }
    ui->lAX->setText("acc" + QString::number(dati[0], 'f', 2) + "g\t" + QString::number(dati[1], 'f', 2) + "g\t");
}
