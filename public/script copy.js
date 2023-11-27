// public/script.js
async function executarCpp() {
  const valor1 = document.getElementById('valor1').value;
  const valor2 = document.getElementById('valor2').value;

  const response = await fetch('/executar', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ valor1, valor2 }),
  });

  const data = await response.json();

  const outputDiv = document.getElementById('output');
  outputDiv.innerHTML = data.output;

  mostrarEvolucao(data.queensPositions);
}

function mostrarEvolucao(queensPositions) {
  const boardContainer = document.getElementById('board-container');
  boardContainer.innerHTML = ''; // Limpar o conteúdo anterior

  queensPositions.forEach(position => {
    const queenDiv = document.createElement('div');
    queenDiv.className = 'queen';
    queenDiv.style.top = `${position.y * 50}px`;
    queenDiv.style.left = `${position.x * 50}px`;
    boardContainer.appendChild(queenDiv);
  });
}
