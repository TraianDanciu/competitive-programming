#include <stdio.h>

#define MAXN 10000
#define MAXCF 14
#define INFINIT 1000000000

int nv[MAXN];
long long v[MAXN][MAXCF + 1];
unsigned long long dp[2][1 << MAXCF];

static inline unsigned long long max(unsigned long long a,
                                     unsigned long long b) {
  return a > b ? a : b;
}

int main() {
  int n, i, mask, bit;
  long long val, p10st, p10dr;

  #ifndef LOCAL
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
  #endif

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%lld", &val);

    p10st = 1;
    while(p10st <= val) {
      p10st *= 10;
    }
    
    nv[i] = 0;
    p10dr = 1;
    while(p10st > 1) {
      v[i][nv[i]++] = (val % p10st) * p10dr + val / p10st;
      p10st /= 10;
      p10dr *= 10;
    }
  }


  for(i = 0; i < n; i++) {
    for(mask = (1 << MAXCF) - 1; mask >= 0; mask--) {
      dp[i % 2][mask] = dp[1 - i % 2][mask] + v[i][0];
      for(bit = 0; bit < nv[i]; bit++) {
        if(mask & (1 << bit)) {
          dp[i % 2][mask] = max(dp[i % 2][mask],
                   dp[1 - i % 2][mask ^ (1 << bit)] + v[i][bit + 1]);
        }
      }
    }
  }

  printf("%llu\n", dp[1 - n % 2][(1 << MAXCF) - 1]);
  return 0;
}
