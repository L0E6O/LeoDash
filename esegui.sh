echo "🔄 Aggiornamento codice..."
cd /home/leo/LeoDash/ #entro nella directory del progetto
git pull #scarico eventuali aggiornamenti da git

echo "🔨 Compilazione..."
cmake . && make #compilo C++

echo "🚀 Avvio LeoDash in background..."
./LeoDash & #avvio l'eseguibile C++ creato dalla compilazione in bacground con '&'
LEODASH_PID=$! #salvo in questa variabile il PID del programma C++

# Aspetta un po' per verificare che LeoDash sia partito correttamente
sleep 2

if ! kill -0 $LEODASH_PID 2>/dev/null; then #se il processo non esiste (kill -0 <PID> ritorna 0 [interpretato come vero] o altro) abortisce
    echo "❌ Errore: LeoDash non è riuscito a partire"
    exit 1
fi

echo "✅ LeoDash avviato con PID: $LEODASH_PID"

echo "🐳 Avvio webserver React..."
cd /home/leo/LeoDash/server/docker/leodash-web/ #vado nella sotto-directory del container react
./startup-webapp.sh #avvio lo script per l'avvio della webapp

echo "✅ Tutto avviato con successo!"
echo "📝 Per fermare LeoDash: kill $LEODASH_PID"
echo "📝 Per fermare il webserver: docker compose down"
