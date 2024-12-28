#include <stdio.h>

#define MAXN 200000

int ult[MAXN], minus[MAXN], plus[MAXN];
long long v[MAXN];

int main() {
  int n, i, x, y, q, l, r;

  freopen("sircost.in", "r", stdin);
  freopen("sircost.out", "w", stdout);
  
  scanf("%d%d", &n, &x);
  ult[0] = -1;
  for(i = 1; i < n; i++) {
    if(i > 1)
      ult[i - 1] = ult[i - 2];
    
    scanf("%d", &y);
    if(x == y)
      ult[i - 1] = i - 1;
    else if(x < y) {
      plus[i - 1]++;
      v[i - 1] += i;
    } else {
      minus[i - 1]++;
      v[i - 1] -= i;
    }
    
    v[i] = v[i - 1];
    plus[i] = plus[i - 1];
    minus[i] = minus[i - 1];
    
    x = y;
  }
  
  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    l--;
    r -= 2;
    
    if(ult[r] < l)
      printf("%lld\n", v[r] - v[l - 1] - l * (plus[r] - plus[l - 1] - minus[r] + minus[l - 1]));
    else
      printf("%lld\n", v[r] - v[ult[r]] - l * (plus[r] - plus[ult[r] - 1] - minus[r] + minus[ult[r] - 1]));
  }
  
  return 0;
}
