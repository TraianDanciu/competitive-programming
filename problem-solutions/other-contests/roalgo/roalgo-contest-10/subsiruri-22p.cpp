#include <bits/stdc++.h>

using namespace std;

#define MAXLIT 26
#define MAXN 100000
#define MAXK MAXLIT
#define MOD 998244353

char a[MAXK + 1], b[MAXN + 1];
int dp[MAXK + 1], poz[MAXLIT];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int k, n;
  cin >> k >> n;
  for(int i = 1; i <= k; i++) {
    cin >> a[i];
    poz[a[i] - 'a'] = i;
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] = poz[b[i] - 'a'];
  }
  
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    
    dp[0] = 1;
    for(int i = l; i <= r; i++) {
      if(b[i] > 0) {
        dp[b[i]] += dp[b[i] - 1];
        if(dp[b[i]] >= MOD) {
          dp[b[i]] -= MOD;
        }
      }
    }
    cout << dp[k] << '\n';
    
    for(int i = 0; i <= k; i++) {
      dp[i] = 0;
    }
  }
  return 0;
}
