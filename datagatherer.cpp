#include <iostream>
#include <unistd.h>   // usleep
#include "MPU6050.h"
#include "datagatherer.h"

MPU6050 accelgyro(0x68); // indirizzo di default 0x68

int16_t ax, ay, az;
int16_t gx, gy, gz;

DataGatherer::DataGatherer()  {
    std::cout << "Inizializzazione del dispositivo I2C..." << std::endl;
    accelgyro.initialize("/dev/i2c-1");

    std::cout << "Verifico connessione...";
    if (accelgyro.testConnection()) {
        std::cout << "Dispositivo connesso, inizio normale operazione..." << std::endl;
    } else {
        throw 1;
    }
}

void DataGatherer::prendiDati(int16_t dati[]){

    // Lettura valori raw
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Stampa formattata
    std::cout << "a/g: "
              << ax << "\t" << ay << "\t" << az << "\t"
              << gx << "\t" << gy << "\t" << gz << std::endl;
    dati[0] = ax;
    dati[1] = ay;
    dati[2] = az;
    dati[3] = gx;
    dati[4] = gy;
    dati[5] = gz;
}
