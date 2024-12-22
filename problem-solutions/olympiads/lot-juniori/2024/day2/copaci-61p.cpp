// is_digit[cf][l][c] = daca mat[l][c] = cf, iar reach[i][l][c] = daca la pasul i
// putem ajunge la (l, c). La inceput reach[0][l][c] = 1 pentru ca putem pleca
// din toate punctele. Apoi trebuie sa gasim un vecin la care sa fi putut ajunge
// la pasul trecut si sa fie valoarea care e la pasul curent.

#include <stdio.h>
#include <ctype.h>

const int MAXN = 100;
const int MAXCF = 10;
const int NUM_LINES = 2;

FILE *fin, *fout;

int n, answer;
char mat[MAXN + 1][MAXN + 1], reach[NUM_LINES][MAXN + 2][MAXN + 2];

void openFiles() {
  fin = fopen("copaci.in", "r");
  fout = fopen("copaci.out", "w");
}

void readMatrix() {
  int l, c;
  fscanf(fin, "%d ", &n);
  for(l = 1; l <= n; l++) {
    for(c = 1; c <= n; c++) {
      mat[l][c] = fgetc(fin) - '0';
      reach[0][l][c] = 1;
    }
    fgetc(fin); // '\n'
  }
}

void processString() {
  int l, c, ch, found, poz;
  answer = poz = 0;
  found = 1;
  while(found && isdigit(ch = fgetc(fin))) {
    ch -= '0';

    found = 0;
    for(l = 1; l <= n; l++) {
      for(c = 1; c <= n; c++) {
        reach[1 - poz][l][c] = 0;
        if(mat[l][c] == ch) { // Trebuie sa fie cifra ch
          // Incercam toate directiile (Nord, Est, Sud, respectiv Vest)
          reach[1 - poz][l][c] = reach[poz][l - 1][c] | reach[poz][l][c + 1] |
                                  reach[poz][l + 1][c] | reach[poz][l][c - 1];
          found |= reach[1 - poz][l][c];
        }
      }
    }

    if(found) {
      poz = 1 - poz;
      answer++;
    }
  }
}

void writeAnswer() {
  fprintf(fout, "%d\n", answer);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  readMatrix();
  processString();
  writeAnswer();
  closeFiles();
  return 0;
}
