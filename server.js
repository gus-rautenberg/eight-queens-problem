// server.js
const express = require('express');
const { exec } = require('child_process');

const app = express();
const port = 3000;

app.use(express.static('public'));
app.use(express.json());

app.post('/executar', (req, res) => {
  const { valor1, valor2 } = req.body;

  const comando = `./sa ${valor1} ${valor2}`;

  exec(comando, (error, stdout, stderr) => {
    if (error) {
      res.status(500).json({ error: `Erro ao executar o comando: ${error.message}` });
      return;
    }
    if (stderr) {
      res.status(500).json({ error: `Erro no stderr: ${stderr}` });
      return;
    }
    res.json({ output: stdout });
  });
});

app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});


