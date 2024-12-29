#include <stdio.h>
#include <bitset>

#define MAXA 2000001

std::bitset<MAXA + 1> ciur;

int main() {
  int t, i, j, n, cnt, p, a;
  
  ciur[0] = ciur[1] = 1;
  for(i = 2; i * i <= MAXA; i++) {
    if(ciur[i] == 0) {
      for(j = i * i; j <= MAXA; j += i) {
        ciur[j] = 1;
      }
    }
  }
  
  scanf("%d%d", &t, &n);
  cnt = 0;
  if(t == 1) {
    for(i = 0; i < n; i++) {
      scanf("%d", &a);
      if(ciur[a] == 0 && ciur[2 * a + 1] == 0) {
        cnt++;
      }
    }
  } else {
    for(i = 0; i < n; i++) {
      scanf("%d", &a);
      p = 1;
      while(p <= a) {
        p *= 10;
      }
      while(ciur[a % p] == 0) {
        p /= 10;
      }
      if(p == 1) {
        cnt++;
      }
    }
  }
  
  printf("%d\n", cnt);
  return 0;
}
