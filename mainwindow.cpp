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
    ui->centralwidget->setStyleSheet("#centralwidget { background-image: url(./clio.png); }");
    ui->Tabs->setStyleSheet("QWidget{background:transparent} QTabWidget::pane{border: 1px;border-color:red;background-color: transparent;} QTabBar::tab {background-color: transparent;color: #ccc;width: 280px;height:48px;font-size:24px} QTabBar::tab:hover{background-color:#ddd; color: white;} QTabBar::tab:selected{background-color: #363535; color: #008BEA;}");
    ui->lAX->setStyleSheet({"#lAX {background-color: rgb(0,0,0); color: white; border-radius: 30px;}"});
    ui->lAY->setStyleSheet({"#lAY {background-color: rgb(0,0,0); color: white; border-radius: 30px;}"});
    ui->lGX->setStyleSheet({"#lGX {background-color: rgb(0,0,0); color: white; border-radius: 30px;}"});
    ui->lGY->setStyleSheet({"#lGY {background-color: rgb(0,0,0); color: white; border-radius: 30px;}"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scriviDati(float dati[]){
    QObject::connect(&timerX, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        ui->lAX->setStyleSheet({"#lAX {background-color: rgb(0,0,0); color: white; border-radius: 30px;}"});
    });
    QObject::connect(&timerY, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        ui->lAY->setStyleSheet({"#lAY {background-color: rgb(0,0,0); color: white; border-radius: 30px;}"});
    });

    if((dati[0] > 7) || (dati[0] < -7)){
        ui->lAX->setStyleSheet({"#lAX {background-color: red; border-radius: 30px;}"});
        timerX.start(2000);
    }
    if((dati[1] > 7) || (dati[1] < -7)){
        ui->lAY->setStyleSheet({"#lAY {background-color: red; border-radius: 30px;}"});
        timerY.start(2000);
    }
    ui->lAX->setText("accX" + QString::number(dati[0], 'f', 2));
    ui->lAY->setText("accY" + QString::number(dati[1], 'f', 2));
    ui->lGX->setText("accX" + QString::number(dati[3], 'f', 2));
    ui->lGY->setText("accY" + QString::number(dati[4], 'f', 2));
}
