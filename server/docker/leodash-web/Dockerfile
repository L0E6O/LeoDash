# Utilizza l'immagine Node.js ufficiale
FROM node:18-alpine

# Imposta la directory di lavoro
WORKDIR /app

# Copia i file package.json e package-lock.json (se presente)
COPY package*.json ./

# Installa le dipendenze
RUN npm install

# Copia il resto del codice dell'applicazione
COPY . .

# Esponi la porta 3000 (React development server)
EXPOSE 3000

# Comando per avviare l'applicazione in modalità sviluppo
CMD ["npm", "start"]
