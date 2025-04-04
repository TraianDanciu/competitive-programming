#include <stdio.h>

const int MAXN = 500;
const int MOD = 10;
const int INV3 = 7; // inversul modular al lui 3 modulo 10

FILE *fin, *fout;
int n, m, p, q, dp[MAXN + 1][MAXN + 1], suff[MAXN + 1][MAXN + 2];

void openFiles() {
  fin = fopen("smsm.in", "r");
  fout = fopen("smsm.out", "w");
}

void readData() {
  fscanf(fin, "%d%d%d%d", &n, &m, &p, &q);
}

int max(int a, int b) {
  return a > b ? a : b;
}

void computeDp() {
  int i, j, prod;
  prod = 1;
  for(i = 0; i <= n; i++) {
    for(j = 0; j < m; j++) {
      prod = (prod * 3) % 10;
    }

    suff[i][m + 1] = 0;
    for(j = m; j >= 0; j--) {
      dp[i][j] = (i == 0 ? 0 : suff[i - 1][j + 1]) + (prod * p) % q;
      suff[i][j] = max(suff[i][j + 1], dp[i][j]);
      if(i > 0) {
        suff[i][j] = max(suff[i][j], suff[i - 1][j]);
      }
      
      prod = (prod * INV3) % 10;
    }
    prod = (prod * 3) % 10; // Inmultisem o data prea mult cu INV3
    prod = (prod * 2) % 10;
  }
}

void writeAnswer() {
  int i, j, answer;
  answer = 0;
  for(i = 0; i <= n; i++) {
    for(j = 0; j <= m; j++) {
      answer = max(answer, dp[i][j]);
    }
  }
  fprintf(fout, "%d\n", answer);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  readData();
  computeDp();
  writeAnswer();
  closeFiles();
  return 0;
}
