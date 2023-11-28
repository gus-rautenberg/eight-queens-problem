
const express = require('express');
const { execSync } = require('child_process');
const fs = require('fs');

const app = express();
const port = 3000;

app.use(express.static('public'));

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

app.get('/run', (req, res) => {
    const command = 'g++ -o breadth breadth.cpp breadth_first.cpp board.cpp && ./breadth n';

    try {
        const stdout = execSync(command, { stdio: 'inherit' });

        // Verificar se o arquivo JSON foi gerado
        if (fs.existsSync('output.json')) {
            try {
                const queensResult = require('./output.json');
                // console.log('Queens result:', queensResult);

                res.json(queensResult);
            } catch (error) {
                console.error('Erro ao ler o arquivo output.json:', error);
                return res.status(500).json({ error: 'Erro ao ler o arquivo output.json', details: error.message });
            }
        } else {
            console.error('O arquivo output.json não foi gerado');
            return res.status(500).json({ error: 'O arquivo output.json não foi gerado' });
        }
    } catch (error) {
        console.error(`Erro na execução: ${error}`);
        return res.status(500).json({ error: 'Erro na execução do programa em C++', details: error.message });
    }
});

app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});
