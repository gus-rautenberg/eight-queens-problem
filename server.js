const express = require('express'); const { execSync } = require('child_process'); const fs = require('fs');

const app = express(); const port = 3000;

app.use(express.static('public'));

app.get('/', (req, res) => { res.sendFile(__dirname + '/index.html'); });

app.get('/run', (req, res) => {
    res.setHeader('Cache-Control', 'no-store, no-cache, must-revalidate, private');

    const command = 'g++ -o breadth breadth.cpp breadth_first.cpp board.cpp && ./breadth n';

    try {
        const stdout = execSync(command, { stdio: 'inherit' });

        setTimeout(() => {
            delete require.cache[require.resolve('./output.json')];

            try {
                let data = fs.readFileSync('output.json', 'utf8');
                let jsonData = JSON.parse(data);
                console.log(jsonData);
                res.json(jsonData);
                fs.unlinkSync('output.json');
            } catch (error) {
                console.error('Erro ao ler o arquivo output.json:', error);
                return res.status(500).json({ error: 'Erro ao ler o arquivo output.json', details: error.message });
            }
        }, 100);
    } catch (error) {
        console.error(`Erro na execução: ${error}`);
        return res.status(500).json({ error: 'Erro na execução do programa em C++', details: error.message });
    }
});

app.get('/runSA', (req, res) => {
    res.setHeader('Cache-Control', 'no-store, no-cache, must-revalidate, private');

    const command = 'g++ -o sa saMain.cpp board.cpp sa.cpp && ./sa n 10000 0.65';

    try {
        const stdout = execSync(command, { stdio: 'inherit' });

        setTimeout(() => {
            delete require.cache[require.resolve('./output.json')];

            try {
                let data = fs.readFileSync('output.json', 'utf8');
                let jsonData = JSON.parse(data);
                console.log(jsonData);
                res.json(jsonData);
                fs.unlinkSync('output.json');
            } catch (error) {
                console.error('Erro ao ler o arquivo output.json:', error);
                return res.status(500).json({ error: 'Erro ao ler o arquivo output.json', details: error.message });
            }
        }, 100);
    } catch (error) {
        console.error(`Erro na execução: ${error}`);
        return res.status(500).json({ error: 'Erro na execução do programa em C++', details: error.message });
    }
});

app.listen(port, () => {
    console.log(`Servidor rodando em http://localhost:${port}`);
});
