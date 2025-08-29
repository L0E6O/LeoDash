#!/bin/bash
cd /home/leo/LeoDash/ #vado nella directory del progetto
export DISPLAY=:0 #imposto la destinazione dell'esecuzione sull rpi5 (nella teoria dice di eseguire il comando sullo schermo primario locale)
./esegui.sh #eseguo il comando di esecuzione normale
