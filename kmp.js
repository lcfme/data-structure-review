function easyIndexOf(str = '', sub = '') {
  let i = 0,
    j = 0,
    k = i;
  while (i < str.length && j < sub.length) {
    if (str[i] === sub[j]) {
      i += 1;
      j += 1;
    } else {
      i = ++k;
      j = 0;
    }
  }
  if (j === sub.length) {
    return k;
  } else {
    return -1;
  }
}

function kmp(str = '', sub = '') {
  let i = 0,
    j = -1,
    next = getNext(str);
  while (i < str.length && j < sub.length) {
    if (j === -1 || j < sub.length) {
      i += 1;
      j += 1;
    } else {
      j = next[j];
    }
    console.log(`i${i}:j${j}`);
  }
  if (j === sub.length) {
    return i - j;
  } else {
    return -1;
  }
}

function getNext(str) {
  var arr = [],
    i = 0,
    j = -1;
  arr[0] = -1;
  while (i < str.length) {
    if (j === -1 || str[i] === str[j]) {
      i += 1;
      j += 1;
      arr[i] = j;
    } else {
      j = arr[j];
    }
  }
  return arr;
}
kmp('ABABABCA');

/*
A|B|A|B|A|B|A|B|C|A

  1 2 3 4 5 6 7 8
  A|B|A|B|A|B|C|A
n|0|0|1|2|3|4|0|1
  

*/
