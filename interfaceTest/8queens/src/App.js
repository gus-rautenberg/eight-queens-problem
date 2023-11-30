import React, { useState, useEffect } from 'react';
import './App.css';

function App() {
  const [iteration, setIteration] = useState('');
  const [queensResult, setQueensResult] = useState([]);
  const [chessboard, setChessboard] = useState(createInitialChessboard());
  const [controller, setController] = useState(new AbortController());

  useEffect(() => {
    fetchData('/run', controller);
    // Cleanup controller when component unmounts
    return () => controller.abort();
  }, [controller]);

  const createInitialChessboard = () => {
    const matrix = [];
    for (let row = 0; row < 8; row++) {
      matrix[row] = [];
      for (let col = 0; col < 8; col++) {
        matrix[row][col] = '';
      }
    }
    return matrix;
  };

  const fetchData = (url, prevController) => {
    // Cancel previous request
    prevController.abort();

    const newController = new AbortController();
    setController(newController);

    fetch(url, { signal: newController.signal })
      .then(response => response.json())
      .then(data => {
        console.log('Queens result:', data);
        updateChessboard(data);
      })
      .catch(error => {
        // Ignore AbortError caused by the controller.abort()
        if (error.name !== 'AbortError') {
          console.error('Erro na execução:', error);
        }
      });
  };

  const updateChessboard = (queensResult) => {
    setQueensResult(queensResult);
    document.getElementById('button1').disabled = true;
    document.getElementById('button2').disabled = true;
    queensResult.forEach((queen, index) => {
      if (queen.length > 0) {
        setTimeout(() => {
          clearChessboard();
          queen.forEach((position) => {
            const { x, y } = position;
            if (x >= 0 && x < 8 && y >= 0 && y < 8) {
              setChessboard(prevChessboard => {
                const newChessboard = [...prevChessboard];
                newChessboard[x][y] = 'Q';
                return newChessboard;
              });
            }
          });
          setIteration(`Iteration: ${index + 1}`);
          if (index !== queensResult.length - 1) {
            setTimeout(() => {
              clearChessboard();
            }, 3);
          }
        }, index * 5);
      }
    });
    document.getElementById('button1').disabled = false;
    document.getElementById('button2').disabled = false;
  };

  const clearChessboard = () => {
    setChessboard(createInitialChessboard());
  };

  const runQueens = () => {
    fetchData('/run', controller);
  };

  const runQueensSA = () => {
    fetchData('/runSA', controller);
  };

  return (
    <div className="App">
      <button id ="button1" onClick={runQueens}>Compilar e Executar Breadth</button>
      <button id ="button2" onClick={runQueensSA}>Compilar e Executar SA</button>
      <div id="chessboard-container">
        {chessboard.map((row, rowIndex) => (
          <div key={rowIndex} className="chessboard-row">
            {row.map((square, colIndex) => (
              <div key={colIndex} className={`square ${((rowIndex + colIndex) % 2 === 0) ? 'white' : 'black'}`}>
                {square}
              </div>
            ))}
          </div>
        ))}
      </div>
      <h1 id="iteration">{iteration}</h1>
    </div>
  );
}

export default App;
