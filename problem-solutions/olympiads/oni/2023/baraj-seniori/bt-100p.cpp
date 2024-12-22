#include <stdio.h>

const int MAXN = 500;
const int MOD = 1'000'000'007;

int v[2 * MAXN + 2], dp[2 * MAXN + 1][2 * MAXN], comb[2 * MAXN][2 * MAXN], n;
long long answer;

FILE *fin, *fout;

void openFiles() {
  fin = fopen("bt.in", "r");
  fout = fopen("bt.out", "w");
}

void readArray() {
  int i;
  fscanf(fin, "%d", &n);
  for(i = 1; i <= n; i++) {
    fscanf(fin, "%d", &v[i]);
    v[n + i] = v[i];
  }
  v[0] = v[n];
}

void computeCombinations() {
  int i, j;
  comb[0][0] = 1;
  for(i = 1; i < 2 * n; i++) {
    comb[i][0] = 1;
    for(j = 1; j <= i; j++) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
      if(comb[i][j] >= MOD) {
        comb[i][j] -= MOD;
      }
    }
  }
}

void computeDp() {
  int i, l, r, k;
  
  for(i = 1; i <= 2 * n; i++) {
    dp[i][i - 1] = 1; // interval vid
  }

  for(l = 2 * n - 1; l > 0; l--) {
    dp[l][l] = 1;
    for(r = l + 1; r < 2 * n; r++) {
      for(k = l; k <= r; k++) {
        if(v[l - 1] != v[k] && v[k] != v[r + 1]) {
          dp[l][r] = (dp[l][r] + 1LL * dp[l][k - 1] * dp[k + 1][r] % MOD
                                               * comb[r - l][k - l]) % MOD;
        }
      }
    }
  }
}

void computeAnswer() {
  int i, good_array;

  if(n == 1) {
    answer = 1;
  } else {
    good_array = 1;
    for(i = 1; i <= n; i++) {
      if(v[i] == v[i + 1]) {
        good_array = 0;
      }
    }

    answer = 0;
    if(good_array) {
      for(i = 1; i <= n; i++) {
        answer += dp[i][i + n - 2];
      }
    }
  }
}

void writeAnswer() {
  fprintf(fout, "%lld\n", answer % MOD);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  readArray();
  computeCombinations();
  computeDp();
  computeAnswer();
  writeAnswer();
  closeFiles();
  return 0;
}
