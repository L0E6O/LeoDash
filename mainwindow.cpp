#include "mainwindow.h"
#include <iostream>
#include "./ui_mainwindow.h"
#include <QTimer>

 QTimer timerX; //un timer
 QTimer timerY; //un timer

 bool mode = false;
 QString textColor = "white";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("#centralwidget { background-image: url(./clio.png); }");
    ui->Tabs->setStyleSheet("QWidget{background:transparent} QTabWidget::pane{border: 1px;border-color:red;background-color: transparent;} QTabBar::tab {background-color: transparent;color: #ccc;width: 280px;height:48px;font-size:24px} QTabBar::tab:hover{background-color:#ddd; color: white;} QTabBar::tab:selected{background-color: #363535; color: #008BEA;}");
    ui->lAX->setStyleSheet({"#lAX {background-color: rgba(0,0,0,0); color: white;}"});
    ui->lAY->setStyleSheet({"#lAY {background-color: rgba(0,0,0,0); color: white;}"});
    ui->lGX->setStyleSheet({"#lGX {background-color: rgba(0,0,0,0); color: white;}"});
    ui->lGY->setStyleSheet({"#lGY {background-color: rgba(0,0,0,0); color: white;}"});
    ui->offButton->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/poweroff.svg"));
    ui->offButton->setStyleSheet("QToolButton:hover{background: none; border:none;}");
    ui->modeButton->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/mode.svg"));
     ui->modeButton->setStyleSheet("QToolButton:hover{background: none; border:none;}");
    QObject::connect(ui->offButton, &QToolButton::clicked, this, [&](){
        std::cout << "---CHIUSURA APPLICAZIONE---" << std::endl;
        exit(0);
    });
    QObject::connect(ui->modeButton, &QToolButton::clicked, this, [&](){
        mode = !mode;
        if(mode){
            textColor = "black";
            ui->lAX->setStyleSheet({"#lAX {color: " + textColor + ";}"});
            ui->lAY->setStyleSheet({"#lAY {color: " + textColor + ";}"});
            ui->lGX->setStyleSheet({"#lGX {color: " + textColor + ";}"});
            ui->lGY->setStyleSheet({"#lGY {color: " + textColor + ";}"});
            ui->Tabs->setStyleSheet("QWidget{background:transparent} QTabWidget::pane{border: 1px;border-color:red;background-color: transparent;} QTabBar::tab {background-color: transparent;color: #000;width: 280px;height:48px;font-size:24px} QTabBar::tab:hover{background-color:#ddd; color: white;} QTabBar::tab:selected{background-color: #D6D3CE; color: #008BEA;}");
            ui->centralwidget->setStyleSheet("#centralwidget { background-image: url(./clio_light.png); }");
            ui->offButton->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/poweroff_dark.svg"));
            ui->modeButton->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/mode_dark.svg"));
        } else {
            textColor = "white";
            ui->lAX->setStyleSheet({"#lAX {color: " + textColor + ";}"});
            ui->lAY->setStyleSheet({"#lAY {color: " + textColor + ";}"});
            ui->lGX->setStyleSheet({"#lGX {color: " + textColor + ";}"});
            ui->lGY->setStyleSheet({"#lGY {color: " + textColor + ";}"});
            ui->Tabs->setStyleSheet("QWidget{background:transparent} QTabWidget::pane{border: 1px;border-color:red;background-color: transparent;} QTabBar::tab {background-color: transparent;color: #ccc;width: 280px;height:48px;font-size:24px} QTabBar::tab:hover{background-color:#ddd; color: white;} QTabBar::tab:selected{background-color: #363535; color: #008BEA;}");
            ui->centralwidget->setStyleSheet("#centralwidget { background-image: url(./clio.png);}");
            ui->offButton->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/poweroff.svg"));
            ui->modeButton->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/mode.svg"));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scriviDati(float dati[]){
    QObject::connect(&timerX, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        ui->lAX->setStyleSheet({"#lAX {color: " + textColor + ";}"});
    });
    QObject::connect(&timerY, &QTimer::timeout, [&]() { //ogni volta che il timer finisce (evento timeout), eseguo la funzione passando tutte le variabili di contesto con [&]
        ui->lAY->setStyleSheet({"#lAY {color: " + textColor + ";}"});
    });

    if((dati[0] > 7) || (dati[0] < -7)){
        ui->lAX->setStyleSheet({"#lAX {color: red;}"});
        timerX.start(2000);
    }
    if((dati[1] > 7) || (dati[1] < -7)){
        ui->lAY->setStyleSheet({"#lAY {color: red;}"});
        timerY.start(2000);
    }
    ui->lAX->setText("accX" + QString::number(dati[0], 'f', 2));
    ui->lAY->setText("accY" + QString::number(dati[1], 'f', 2));
    ui->lGX->setText("gyroX" + QString::number(dati[3], 'f', 2));
    ui->lGY->setText("gyroY" + QString::number(dati[4], 'f', 2));
}
