function Transmat(matrix = []) {
  var t = [];
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (!Array.isArray(t[j])) t[j] = [];
      t[j][i] = matrix[i][j];
    }
  }
  return t;
}

Transmat([[0, 1, 2, 3, 4], [0, 1, 2, 3, 4]]);

function Addmat(matrixA = [], matrixB = []) {
  var r = [];
  for (let i = 0; i < matrixA.length; i++) {
    r[i] = [];
    for (let j = 0; j < matrixA[i].length; j++) {
      r[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }
  return r;
}

Addmat([[1, 2, 3], [4, 5, 6], [7, 8, 9]], [[3, 2, 1], [6, 5, 4], [9, 8, 7]]);

function Mutmat(matrixA, matrixB) {
  var r = [];
  for (let i = 0; i < matrixA.length; i++) {
    r[i] = [];
    for (let j = 0; j < matrixA[i].length; j++) {
      r[i][j] = matrixA[i][j] * matrixB[i][j];
    }
  }
  return r;
}

Mutmat([[2, 2, 2]], [[2, 2, 2]]);
