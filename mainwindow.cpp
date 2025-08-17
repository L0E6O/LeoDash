#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

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
    std::cout<<"dati"<<std::endl;
    ui->lAX->setText("acc" + QString::number(dati[0], 'f', 2) + "g\t" + QString::number(dati[1], 'f', 2) + "g\t" + QString::number(dati[2], 'f', 2) + "g\t");
}
