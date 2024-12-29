#include <stdio.h>
#include <algorithm>

#define MAXN 200000

int v[MAXN + 1], pref[MAXN + 1];

struct Numar {
  int val, poz;
} suma[MAXN + 1];
int compar(Numar a, Numar b) {
  if(a.val == b.val) {
    return a.poz < b.poz;
  }
  return a.val < b.val;
}

static inline int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int q, n, i, st, dr, mij, j, val;
  
  scanf("%d%d", &q, &n);
  for(i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    suma[i].val = suma[i].poz = i;
  }
  
  for(i = 1; i <= n; i++) {
    for(j = i; j <= n; j += i) {
      suma[j].val += v[i];
    }
  }
  
  std::sort(suma + 1, suma + n + 1, compar);
  for(i = 1; i <= n; i++) {
    pref[i] = max(pref[i - 1], suma[i].poz);
  }
  
  while(q--) {
    scanf("%d", &val);
    
    if(suma[1].val > val) {
      printf("-1\n");
    } else {
      st = 1;
      dr = n + 1;
      while(dr - st > 1) {
        mij = (st + dr) / 2;
        if(suma[mij].val > val) {
          dr = mij;
        } else {
          st = mij;
        }
      }
      
      printf("%d\n", pref[st]);
    }
  }
  
  return 0;
}
