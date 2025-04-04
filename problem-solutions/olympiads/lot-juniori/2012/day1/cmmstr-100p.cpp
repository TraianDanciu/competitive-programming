// Ca sa afli primul caracter cauti cel mai scurt sufix care contine
// toate literele distincte din s, iar apoi vei lua cea mai mica litera
// din intervalul [0, suffpoz] (fie prima pozitie a ei poz1).

// Ca sa afli al doilea caracter vei cauta cel mai scurt sufix care
// contine toate literele distincte in afara de prima afisata (asta nu
// inseamna ca sufixul nu poate sa o contina, inseamna ca nu trebuie sa
// o contina neaparat). Vei afisa cea mai mica litera, fara prima, din
// intervalul [poz1, suffpoz]. Notezi cu poz2 prima pozitie a acestei
// litere selectate si continui tot asa

// Voi afla suffpoz facand minimul ultimelor aparitii ale literelor
// neafisate, iar pentru a afla litera minima dintr-un interval, o sa
// caut liniar cea mai mica litera care apare, si ca sa aflu daca o
// litera apare o sa caut binar in vectorul ei de pozitii

// Complexitate: O(N + SIGMA*SIGMA*logN)

#include <stdio.h>
#include <ctype.h>
#include <vector>

FILE *fin, *fout;

const int MAXN = 3'000'000;
const int SIGMA = 26;

int n;
std::vector<int> poz[SIGMA];
char viz[SIGMA];

void openFiles() {
  fin = fopen("cmmstr.in", "r");
  fout = fopen("cmmstr.out", "w");
}

void readData() {
  int ch;
  while(isalpha(ch = fgetc(fin))) {
    poz[ch - 'a'].push_back(n++);
  }
}

int pozInterval(int ch, int l, int r) {
  int st, dr, mij;

  if(poz[ch].back() < l) {
    return -1;
  }
  
  st = -1;
  dr = (int)poz[ch].size() - 1;
  while(dr - st > 1) {
    mij = (st + dr) / 2;
    if(poz[ch][mij] < l) {
      st = mij;
    } else {
      dr = mij;
    }
  }
  return poz[ch][dr];
}

int min(int a, int b) {
  return a < b ? a : b;
}

void computeAnswer() {
  int i, num_distinct, j, suffpoz, poz_last, new_poz_last;

  num_distinct = 0;
  for(i = 0; i < SIGMA; i++) {
    if(!poz[i].empty()) {
      num_distinct++;
    } else {
      viz[i] = 1;
    }
  }

  poz_last = 0;
  for(i = 0; i < num_distinct; i++) {
    suffpoz = n;
    for(j = 0; j < SIGMA; j++) {
      if(!viz[j]) {
        suffpoz = min(suffpoz, poz[j].back());
      }
    }

    j = 0;
    while(viz[j] || (new_poz_last = pozInterval(j, poz_last, suffpoz)) == -1 || new_poz_last > suffpoz) {
      j++;
    }
    fputc('a' + j, fout);
    viz[j] = 1;
    poz_last = new_poz_last;
  }
  fputc('\n', fout);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readData();
  computeAnswer();
  closeFiles();
  return 0;
}
