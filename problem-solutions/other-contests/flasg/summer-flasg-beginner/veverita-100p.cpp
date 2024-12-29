#include <stdio.h>
#include <algorithm>

#define MAXN 500000

int v[MAXN], n;

int cateLEQ(int val) {
  int st, dr, mij;
  
  if(v[0] > val) {
    return -1;
  }
  
  st = 0;
  dr = n;
  while(dr - st > 1) {
    mij = (st + dr) / 2;
    if(v[mij] > val) {
      dr = mij;
    } else {
      st = mij;
    }
  }
  
  return st;
}

int main() {
  int t, i, x, y;
  long long total;
  
  scanf("%d%d", &n, &t);
  for(i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  std::sort(v, v + n);
  
  total = 0;
  for(i = 0; i < t; i++) {
    scanf("%d%d", &x, &y);
    total += cateLEQ(y) - cateLEQ(x - 1);
  }
  
  printf("%lld\n", total);
  return 0;
}
