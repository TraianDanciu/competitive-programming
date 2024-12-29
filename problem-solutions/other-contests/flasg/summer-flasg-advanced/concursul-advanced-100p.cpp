#include <stdio.h>

#define MAXN 1000

int v[MAXN + 1];

static inline int abs(int x) {
  return x > 0 ? x : -x;
}

int main() {
  int t, n, x, i, suma, posib;
  
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &x);
    for(i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    
    i = 0;
    v[n] = 0;
    while(v[i] == x) {
      i++;
    }
    
    if(i == n) {
      printf("0\n");
    } else {
      suma = posib = 0;
      for(i = 0; i < n; i++) {
        if(v[i] == x) {
          posib += 5000 - abs(x);
        } else {
          suma += v[i] - x;
        }
      }
      
      if(abs(suma) <= posib) {
        printf("1\n");
      } else {
        printf("2\n");
      }
    }
  }
  
  return 0;
}
