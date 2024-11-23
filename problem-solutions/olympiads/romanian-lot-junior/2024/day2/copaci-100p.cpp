// is_digit[cf][l][c] = daca mat[l][c] = cf, iar reach[i][l][c] = daca la pasul i
// putem ajunge la (l, c). La inceput reach[0][l][c] = 1 pentru ca putem pleca
// din toate punctele. Apoi trebuie sa gasim un vecin la care sa fi putut ajunge
// la pasul trecut si sa fie valoarea care e la pasul curent.

// Voi compresa cele doua matrici, si ca sa le pot parcurge in O(1) le voi tine
// intr-un int128 (ca sa pot avea cate un bit pentru fiecare linie).

#include <stdio.h>
#include <ctype.h>

const int MAXN = 100;
const int MAXCF = 10;

FILE *fin, *fout;

int n, answer;
__int128 is_digit[MAXCF][MAXN + 1], reach[2][MAXN + 2];

void openFiles() {
  fin = fopen("copaci.in", "r");
  fout = fopen("copaci.out", "w");
}

void readMatrix() {
  int l, c;
  fscanf(fin, "%d ", &n);
  for(l = 1; l <= n; l++) {
    for(c = 1; c <= n; c++) {
      is_digit[fgetc(fin) - '0'][l] |= (__int128)1 << c;
    }
    fgetc(fin); // '\n'

    reach[0][l] = ((__int128)1 << (n + 1)) - 2; // 011111..1 de n ori
  }
}

void processString() {
  int l, ch, found, poz;
  answer = poz = 0;
  found = 1;
  while(found && isdigit(ch = fgetc(fin))) {
    ch -= '0';

    found = 0;
    for(l = 1; l <= n; l++) {
      // Incercam toate directiile (Nord, Est, Sud, respectiv Vest)
      reach[1 - poz][l] = reach[poz][l - 1] | (reach[poz][l] >> 1) |
                          reach[poz][l + 1] | (reach[poz][l] << 1);
      reach[1 - poz][l] &= is_digit[ch][l]; // Trebuie sa fie cifra ch
      found |= (reach[1 - poz][l] > 0);
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
