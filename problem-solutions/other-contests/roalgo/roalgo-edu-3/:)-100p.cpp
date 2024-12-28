#include <stdio.h>
#include <map>

#define MAXN 200000

int v[MAXN + 1];
std::map<int, char> viz;

int main() {
  int t, n, i, cnt;

  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    cnt = 0;
    for(i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      v[i] ^= v[i - 1];

      if(viz.count(v[i])) {
        viz.clear();
        cnt++;
      }

      viz[v[i]] = 1;
    }

    printf("%d\n", cnt);
    viz.clear();
  }
  
  return 0;
}

