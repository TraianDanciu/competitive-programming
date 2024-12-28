#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5;
long long dp[3];
int a[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n >> a[1];
  for(int i = 2; i <= n; i++) {
    cin >> a[i % 3];
    int g = __gcd(a[i % 3], a[(i - 1) % 3]);
    long long old = dp[i % 3];
    if(i != 3) {
      dp[i % 3] = dp[(i - 2) % 3] + g;
    } else {
      dp[i % 3] = 0;
    }
    if(i == 3 || i > 4) {
      dp[i % 3] = max(dp[i % 3], old + __gcd(g, a[(i - 2) % 3]));
    }
  }
  cout << dp[n % 3] << "\n";
  return 0;
}
