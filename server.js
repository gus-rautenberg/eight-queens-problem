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
    // Adicionando cabeçalhos para evitar o cache
    res.setHeader('Cache-Control', 'no-store, no-cache, must-revalidate, private');

    const command = 'g++ -o breadth breadth.cpp breadth_first.cpp board.cpp && ./breadth n';

    try {
        // Executar o comando de compilação e execução
        const stdout = execSync(command, { stdio: 'inherit' });

        // Adicionar um temporizador de 1 segundo antes de continuar
        setTimeout(() => {
            // Verificar se o arquivo JSON foi gerado
            if (fs.existsSync('output.json')) {
                try {
                    const queensResult = require('./output.json');
                    res.json(queensResult);
                    fs.unlinkSync('output.json');
                } catch (error) {
                    console.error('Erro ao ler o arquivo output.json:', error);
                    return res.status(500).json({ error: 'Erro ao ler o arquivo output.json', details: error.message });
                }
            } else {
                console.error('O arquivo output.json não foi gerado');
                return res.status(500).json({ error: 'O arquivo output.json não foi gerado' });
            }
        }, 6000); // 1000 milissegundos = 1 segundo
    } catch (error) {
        console.error(`Erro na execução: ${error}`);
        return res.status(500).json({ error: 'Erro na execução do programa em C++', details: error.message });
    }
});

app.get('/runSA', (req, res) => {
    // Adicionando cabeçalhos para evitar o cache
    res.setHeader('Cache-Control', 'no-store, no-cache, must-revalidate, private');

    const command = 'g++ -o sa saMain.cpp board.cpp sa.cpp && ./sa n 10000 0.65';

    try {
        // Executar o comando de compilação e execução
        const stdout = execSync(command, { stdio: 'inherit' });

        // Adicionar um temporizador de 1 segundo antes de continuar
        setTimeout(() => {
            // Verificar se o arquivo JSON foi gerado
            if (fs.existsSync('output.json')) {
                try {
                    const queensResult = require('./output.json');
                    res.json(queensResult);
                    fs.unlinkSync('output.json');
                } catch (error) {
                    console.error('Erro ao ler o arquivo output.json:', error);
                    return res.status(500).json({ error: 'Erro ao ler o arquivo output.json', details: error.message });
                }
            } else {
                console.error('O arquivo output.json não foi gerado');
                return res.status(500).json({ error: 'O arquivo output.json não foi gerado' });
            }
        }, 6000); // 1000 milissegundos = 1 segundo
    } catch (error) {
        console.error(`Erro na execução: ${error}`);
        return res.status(500).json({ error: 'Erro na execução do programa em C++', details: error.message });
    }
});

app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});
