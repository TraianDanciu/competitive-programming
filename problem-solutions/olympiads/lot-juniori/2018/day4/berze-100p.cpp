#include <stdio.h>

const int MAXN = 1'0000;
const int MOD = 700'001;

FILE *fin, *fout;

int n, maxdr[MAXN + 1], dp[MAXN + 1][MAXN + 1], sumdp[MAXN + 1][MAXN + 1];

void openFiles() {
  fin = fopen("berze.in", "r");
  fout = fopen("berze.out", "w");
}

int max(int a, int b) {
  return a > b ? a : b;
}

void readData() {
  int i, m, st, dr;
  fscanf(fin, "%d%d", &n, &m);
  for(i = 0; i < m; i++) {
    fscanf(fin, "%d%d", &st, &dr);
    st++;
    dr++;
    maxdr[st] = max(maxdr[st], dr);
  }
}

void computeRestrictions() {
  int i;
  for(i = 1; i <= n; i++) {
    maxdr[i] = max(maxdr[i], maxdr[i - 1]);
  }
}

int min(int a, int b) {
  return a < b ? a : b;
}

void computeDp() {
  int i, j, st, dr, mij;
  for(i = 1; i <= n; i++) {
    st = 0;
    dr = i;
    while(dr - st > 1) {
      mij = (st + dr) / 2;
      if(maxdr[mij] < i) {
        st = mij;
      } else {
        dr = mij;
      }
    }
  
    dp[i][0] = sumdp[i][0] = 1;
    for(j = 1; j < i; j++) {
      dp[i][j] = sumdp[j][min(st, j - 1)];
      sumdp[i][j] = sumdp[i][j - 1] + dp[i][j];
      if(sumdp[i][j] >= MOD) {
        sumdp[i][j] -= MOD;
      }
    }
  }
}

void writeAnswer() {
  long long answer = 1;
  int i;
  for(i = 1; i <= n; i++) {
    answer += sumdp[i][i - 1];
  }
  fprintf(fout, "%lld\n", answer % MOD);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readData();
  computeRestrictions();
  computeDp();
  writeAnswer();
  closeFiles();
  return 0;
}
