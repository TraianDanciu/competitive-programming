#include <stdio.h>
#include <ctype.h>

const int MAXN = 200'000;
const int LOGN = 18;

FILE *fin, *fout;
char v[MAXN + 1];
int n, prefL[MAXN + 1], suffR[MAXN + 2];

int min(int a, int b) {
  return a < b ? a : b;
}

struct SparseTable {
  int spt[LOGN][MAXN + 1], lg2[MAXN + 2];

  void init() {
    int i, j;
    for(i = 2; i <= n + 1; i++) {
      lg2[i] = 1 + lg2[i >> 1];
    }
    for(i = 0; i <= n; i++) {
      spt[0][i] = prefL[i] + suffR[i + 1];
    }
    for(i = 1; i <= lg2[n]; i++) {
      for(j = 0; j + (1 << i) - 1 <= n; j++) {
        spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  int query(int st, int dr) {
    int lg = lg2[dr - st + 1];
    return min(spt[lg][st], spt[lg][dr - (1 << lg) + 1]);
  }
} rmq;

void openFiles() {
  fin = fopen("excursie.in", "r");
  fout = fopen("excursie.out", "w");
}

void readString() {
  int i, ch;
  fscanf(fin, "%d", &n);
  while(!isalpha(ch = fgetc(fin)));
  for(i = 1; i <= n; i++) {
    v[i] = (ch == 'R');
    ch = fgetc(fin);
  }
}

void computePartialSums() {
  int i;
  for(i = 1; i <= n; i++) {
    prefL[i] = prefL[i - 1] + (1 - v[i]);
  }
  for(i = n; i > 0; i--) {
    suffR[i] = suffR[i + 1] + v[i];
  }
}

void answerQueries() {
  int q, i, st, dr, aux;
  fscanf(fin, "%d", &q);
  for(i = 0; i < q; i++) {
    fscanf(fin, "%d%d", &st, &dr);
    if(st > dr) {
      aux = st;
      st = dr;
      dr = aux;
    }
    fprintf(fout, "%d\n", rmq.query(st - 1, dr) - prefL[st - 1]
                                                           - suffR[dr + 1]);
  }
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  readString();
  computePartialSums();
  rmq.init();
  answerQueries();
  closeFiles();
  return 0;
}
