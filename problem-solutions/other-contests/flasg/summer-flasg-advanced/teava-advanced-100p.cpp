#include <stdio.h>

#define MAXN 500

double dp[MAXN + 1][MAXN + 1];
int v[MAXN + 1];

static inline double max(double a, double b) {
  return a > b ? a : b;
}

int main() {
  int n, k, i, j, suma, min, p;

  scanf("%d%d", &n, &k);
  for(i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  
  suma = 0;
  for(i = 1; i <= n; i++) {
    suma += v[i];
    dp[i][1] = (double)suma / i; 
  }
  for(i = 1; i <= n; i++) {
    min = i < k ? i : k;
    for(j = 2; j <= min; j++) {
      suma = dp[i][j] = 0;
      for(p = i; p >= j; p--) {
        suma += v[p];
        dp[i][j] = max(dp[i][j], dp[p - 1][j - 1] + (double)suma / (i - p + 1));
      }
    }
  }
  
  printf("%.6f\n", dp[n][k]);
  return 0;
}
