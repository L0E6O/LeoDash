#!/bin/bash
IP=$(ip route get 1 | awk '{print $7}') #salvo l'IP nella variabile IP
echo "REACT_APP_API_URL=$IP" > .env #sovrascrivo le variabili d'ambiente
docker compose up -d #avvio il compose in modalità detached