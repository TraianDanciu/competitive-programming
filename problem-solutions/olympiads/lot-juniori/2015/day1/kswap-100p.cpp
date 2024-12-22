// dp[n][k] = numarul de permutari cu n elemente care au k inversiuni
// Daca vrem sa adaugam elementul n la o permutare de ordin n-1, putem forma,
// in functie de unde vrem sa il punem, n-1, n-2, .., sau 0 inversiuni noi.
// Asa ca dp[n][k] = sum(dp[n-1][k-i] | 0 <= i < n).
// Observam ca dp[n][k] - dp[n][k-1] = dp[n-1][k] - dp[n-1][k-n]
// dp[n][k] = dp[n][k-1] + dp[n-1][k] - dp[n-1][k-n]

#include <stdio.h>

const int MAXN = 150;
const int MAXK = MAXN * (MAXN - 1) / 2;
const int MOD = 30103;

int n, k, dp[MAXN + 1][MAXK + 1];

FILE *fin, *fout;

void openFiles() {
  fin = fopen("kswap.in", "r");
  fout = fopen("kswap.out", "w");
}

void readData() {
  fscanf(fin, "%d%d", &n, &k);
}

void computeDp() {
  int i, j, maxj;
  for(i = 1; i <= n; i++) {
    dp[i][0] = 1; // Permutarea identica
    maxj = i * (i - 1) / 2;
    for(j = 1; j <= maxj; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      if(j >= i) {
        dp[i][j] -= dp[i - 1][j - i];
      }
      
      dp[i][j] += MOD;
      while(dp[i][j] >= MOD) {
        dp[i][j] -= MOD;
      }
    }
  }
}

void writeAnswer() {
  fprintf(fout, "%d\n", dp[n][k]);
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
