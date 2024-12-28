#include <stdio.h>

#define MAXN 2000
#define MAXK 1000
#define MAXLIT 26

// dp[i][j] = p maxim astfel incat in [p, i] sa existe un subsir din ala de j
int dp[MAXN + 1][MAXK + 1], primdif[MAXN + 1];
char frecv[MAXLIT], s[MAXN + 1];

static inline int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n, k, i, j, cnt;
  long long ans;
  
  scanf("%d%d ", &n, &k);
  for(i = 1; i <= n; i++) {
    s[i] = fgetc(stdin) - 'a';
    primdif[i] = -1;
  }
  
  // primdif[i] = j < i maxim a.i. s[j] != s[i]
  for(i = 2; i <= n; i++) {
    if(s[i] == s[i - 1]) {
      primdif[i] = primdif[i - 1];
    } else {
      primdif[i] = i - 1;
    }
  }
  
  dp[0][0] = 1;
  ans = 0;
  for(i = 1; i <= n; i++) {
    // varianta in care nu aleg s[i]
    dp[i][0] = i + 1; // schema care nu stiu de ce merge
    for(j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
    }
    
    // ma lipesc la ceva dupa primdif[i]
    if(primdif[i] > 0) {
      for(j = 1; j <= k; j++) {
        dp[i][j] = max(dp[i][j], dp[primdif[i] - 1][j - 1]);
      }
    }
    
    // daca vreau sa se termine la i, trebuie sa fie cel putin dupa dp[i][j]
    ans += dp[i][k];
  }
  
  printf("%lld\n", ans);
  return 0;
}
