echo "🔄 Aggiornamento codice..."
cd /home/leo/LeoDash/
git pull

echo "🔨 Compilazione..."
cmake . && make

echo "🚀 Avvio LeoDash in background..."
./LeoDash &
LEODASH_PID=$!

# Aspetta un po' per verificare che LeoDash sia partito correttamente
sleep 2

if ! kill -0 $LEODASH_PID 2>/dev/null; then
    echo "❌ Errore: LeoDash non è riuscito a partire"
    exit 1
fi

echo "✅ LeoDash avviato con PID: $LEODASH_PID"

echo "🐳 Avvio webserver React..."
cd /home/leo/LeoDash/server/docker/leodash-web/
./startup-webapp.sh

echo "✅ Tutto avviato con successo!"
echo "📝 Per fermare LeoDash: kill $LEODASH_PID"
echo "📝 Per fermare il webserver: docker compose down"
