#include <stdio.h>

#define MAXN 200000
#define INFINIT 1000000001

int a[MAXN];

int main() {
  int t, n, i, r, st, dr, mij;
  long long sum; 

  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &r);
    for(i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }

    if(r < a[0]) {
      printf("-1\n");
    } else {
      st = -1;
      dr = INFINIT;
      while(dr - st > 1) {
        mij = (st + dr) / 2;

        i = 0;
        sum = r;
        while(i < n && sum > 0) {
          sum -= a[i++];
          if(sum > 0) {
            sum += mij;
          }
        }

        if(sum > 0) {
          dr = mij;
        } else {
          st = mij;
        }
      }

      printf("%d\n", dr);
    }
  }
}
