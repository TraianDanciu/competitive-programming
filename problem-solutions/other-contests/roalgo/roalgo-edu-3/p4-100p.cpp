#include <stdio.h>

#define MOD 1000000007
#define MAXM 200

int base[MAXM][MAXM], aux[MAXM][MAXM], rez[MAXM][MAXM], m;

void mult(int a[MAXM][MAXM], int b[MAXM][MAXM]) {
  int i, j, k;

  for(i = 0; i <= m + 1; i++) {
    for(j = 0; j <= m + 1; j++) {
      aux[i][j] = 0;
      for(k = 0; k <= m + 1; k++) {
        aux[i][j] = (aux[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
      }
    }
  }

  for(i = 0; i <= m + 1; i++) {
    for(j = 0; j <= m + 1; j++) {
      a[i][j] = aux[i][j];
    }
  }
}

int main() {
  int t, i, j, sum;
  long long n;

  scanf("%d", &t);
  while(t--) {
    scanf("%lld%d", &n, &m);

    for(i = 0; i <= m + 1; i++) {
      for(j = 0; j <= m + 1; j++) {
        rez[i][j] = base[i][j] = 0;
      }
    }
    for(i = 1; i <= m; i++) {
      rez[i][i] = 1;
    }

    for(i = 1; i <= m; i++) {
      base[i - 1][i] = base[i][i] = base[i + 1][i] = 1;
    }

    n--;
    while(n > 0) {
      if(n % 2) {
        mult(rez, base);
      }
      mult(base, base);
      n /= 2;
    }

    sum = 0;
    for(i = 1; i <= m; i++) {
      for(j = 1; j <= m; j++) {
        sum += rez[i][j];
        if(sum >= MOD) {
          sum -= MOD;
        }
      }
    }
    printf("%d\n", sum);
  }

  return 0;
}
