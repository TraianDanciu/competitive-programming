// Observatie 1: Nu este optim sa folosim nici macar una negativa

// Observatie 2: La inceput putem ajunge in [0, 0], care este interval contiguu.
// Sa presupunem ca pana am ajuns la un i intervalul a fost contiguu. Atunci
// noi vom extinde intervalul cu [i + 1, i + v[i]], deci el va ramane contiguu.
// Concluzia este ca putem ajunge mereu la un interval contiguu de pozitii.

// Observatie 3: Prima data cand ajungem la o pozitie ne va si da rezultatul
// optim.

// Fie dr[i] = capatul stanga al intervalului cand ajungem la i
// Fie rez[i] = numarul de salturi de care avem nevoie sa ajungem la i
// dr[i+1] = dr[i+2] = ... = dr[i+v[i]] = max(dr[i], i+v[i])
// rez[dr[i]+1] = rez[dr[i]+2] = ... = rez[i+v[i]] = rez[i]+1

// Observatie 4: Nu avem nevoie de vectori ca sa facem treaba asta

// Vom face rezolvarea din aproape in aproape
// Pasul 0: Marcam valoarea 0
// Pasul 1: Marcam pana la v[0] si gasim cea mai mare pozitie (max_poz[1])
// Pasul 2: Marcam pana la max_poz[1] si gasim max_poz[2]
// Si asa mai departe

#include <stdio.h>
#include <ctype.h>

const int NEGATIVE = -1;

FILE *fin, *fout;

void openFiles() {
  fin = fopen("salturi.in", "r");
  fout = fopen("salturi.out", "w");
}

int readInt() {
  int ch, n;
  while(isspace(ch = fgetc(fin)));
  if(ch == '-') {
    n = NEGATIVE;
  } else {
    n = 0;
    do {
      n = n * 10 + ch - '0';
    } while(isdigit(ch = fgetc(fin)));
  }
  return n;
}

void scanArray() {
  int i, n, max_poz, new_max_poz, val, step;
  n = readInt();
  max_poz = i = step = 0;
  while(max_poz < n) {
    step++; // Acum facem pasul cu numarul step
    new_max_poz = 0;
    for(; i <= max_poz; i++) {
      val = readInt();
      // Nu folosim valorile negative
      if(val != NEGATIVE && i + val > new_max_poz) {
        new_max_poz = i + val;
      }
    }
    max_poz = new_max_poz;
    printf("%d ", max_poz);
  }
  fprintf(fout, "%d\n", step);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  scanArray();
  closeFiles();
  return 0;
}
