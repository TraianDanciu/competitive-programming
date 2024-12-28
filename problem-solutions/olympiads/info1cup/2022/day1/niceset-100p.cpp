#include <stdio.h>
#include <algorithm>

#define MAXN 300000

int a[MAXN + 2];
long long sp[MAXN + 2];

int main() {
  int n, i, st, dr, mij;
  long long s;
  __int128 min, now;

  scanf("%d%lld", &n, &s);
  for(i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  std::sort(a + 1, a + n + 1);
  for(i = 1; i <= n; i++) {
    sp[i] = sp[i - 1] + a[i];
  }

  st = 1;
  dr = n + 1;
  while(dr - st > 1) {
    mij = (st + dr) / 2;
    now = 0;
    for(i = 1; i <= mij; i++) {
      now += (__int128)(2 * i - 1 - mij) * a[i];
    }

    min = now;
    for(i = mij + 1; i <= n + 1; i++) {
      if(min > now) {
        min = now;
      }
      now += (__int128)(mij - 1) * (a[i] + a[i - mij]);
      now -= 2 * (sp[i - 1] - sp[i - mij]);
    }

    if(min > s) {
      dr = mij;
    } else {
      st = mij;
    }
  }

  printf("%d\n", st);
  return 0;
}
