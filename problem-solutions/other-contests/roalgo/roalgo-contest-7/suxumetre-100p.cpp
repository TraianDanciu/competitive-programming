#include <stdio.h>

const int MAXN = 5'000;
const int MAXM = 30;
const long long INFINIT = 1'000'000'000'000'000'000LL;

int v[MAXN + 1], fr[MAXM], n, k, m;
long long cost[MAXN + 1][MAXN + 1], dp[MAXN + 1][MAXN + 1];

void readData() {
  int i;
  scanf("%d%d%d", &n, &k, &m);
  for(i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
}

void computeIntervals() {
  int st, dr, i, rest;
  long long sum;
  for(st = 1; st <= n; st++) {
    for(i = 0; i < m; i++) {
      fr[i] = 0;
    }
    fr[0] = 1;
    sum = 0;
    for(dr = st; dr <= n; dr++) {
      cost[st][dr] = cost[st][dr - 1];
      sum += v[dr];
      rest = sum % m;
      for(i = 0; i < m; i++) {
        cost[st][dr] += i * fr[(rest - i + m) % m];
      }
      fr[rest]++;
    }
  }
}

int min(int a, int b) {
  return a < b ? a : b;
}

void divide(int k, int st, int dr, int hst, int hdr) {
  int mij, h, i;
  long long aux;
  if(st <= dr) {
    mij = (st + dr) / 2;
    h = 0;
    dp[k][mij] = INFINIT;
    for(i = hst; i <= min(mij, hdr); i++) {
      aux = dp[k - 1][i - 1] + cost[i][mij];
      if(dp[k][mij] > aux) {
        dp[k][mij] = aux;
        h = i;
      }
    }
    divide(k, st, mij - 1, hst, h);
    divide(k, mij + 1, dr, h, hdr);
  }
}

void computeDp() {
  int i;
  for(i = 1; i <= n; i++) {
    dp[1][i] = cost[1][i];
  }
  for(i = 2; i <= k; i++) {
    divide(i, 1, n, 1, n);
  }
}

void writeAnswer() {
  printf("%lld\n", dp[k][n]);
}

int main() {
  readData();
  computeIntervals();
  computeDp();
  writeAnswer();
  return 0;
}
