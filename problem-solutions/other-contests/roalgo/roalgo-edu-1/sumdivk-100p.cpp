#include <stdio.h>

#define MAXR 10000000
#define MAXE 3
#define MOD 1000000007

int nrmod[MAXE + 1][MAXR + 1];

int main() {
  int n, r, i, j, k, newk;
  long long x;
  
  scanf("%d%d", &n, &r);
  nrmod[0][0] = 1;
  for(i = 0; i < n; i++) {
    scanf("%lld", &x);
    x %= r;
    for(j = MAXE; j > 0; j--) {
      for(k = 0; k < r; k++) {
        newk = (k + x) % r;
        nrmod[j][newk] += nrmod[j - 1][k];
        if(nrmod[j][newk] >= MOD) {
          nrmod[j][newk] -= MOD;
        }
      }
    }
  }
  
  printf("%d\n", nrmod[MAXE][0]);
  return 0;
}
