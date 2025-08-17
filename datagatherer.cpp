#include <iostream>
#include <iomanip>
#include <unistd.h>   // usleep
#include "MPU6050.h"
#include "I2Cdev.h"
#include "datagatherer.h"

MPU6050 accelgyro(0x68); // indirizzo di default 0x68

int16_t ax, ay, az;
int16_t gx, gy, gz;

DataGatherer::DataGatherer()  {

    std::cout << "Inizializzazione del dispositivo I2C..." << std::endl;
    I2Cdev::initialize("/dev/i2c-1");
    accelgyro.initialize();

    std::cout << "Verifico connessione...";
    if (accelgyro.testConnection()) {
        std::cout << "Dispositivo connesso, inizio normale operazione..." << std::endl;
    } else {
        throw 1;
    }
}

void DataGatherer::prendiDati(int16_t dati[]){

    // Lettura valori raw
    accelgyro.getMotion6(&gy, &gx, &gz, &ay, &ax, &az);

    // Stampa formattata
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "a/g: "
              << ax/16384.0f << "\t" << ay/16384.0f << "\t" << az/16384.0f << "\t"
              << gx/131.0f << "\t" << gy/131.0f << "\t" << gz/131.0f << std::endl;
    dati[0] = ax;
    dati[1] = ay;
    dati[2] = az;
    dati[3] = gx;
    dati[4] = gy;
    dati[5] = gz;
}
