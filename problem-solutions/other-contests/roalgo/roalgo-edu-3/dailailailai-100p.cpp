#include <stdio.h>

int main() {
  int t, n, i, val, par, ans;

  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    par = ans = 0;
    for(i = 0; i < n; i++) {
      scanf("%d", &val);
      val = (val & 1) ^ par;
      if(val) {
        par ^= 1;
        ans++;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
