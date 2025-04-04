#include <bits/stdc++.h>

using namespace std;

const int nmax = 5e4;
int masks[5 + nmax];

const int mod = 123457;
int dp[2][1 << 10];

int main() {
  ifstream fin("ksiruri.in");
  ofstream fout("ksiruri.out");
  int k, n;
  fin >> k >> n;
  for (int i = 1; i <= n; i++) {
    int m;
    fin >> m;
    while (m--) {
      int cf;
      fin >> cf;
      masks[i] |= 1 << cf;
    }
  }
  reverse(masks + 1, masks + n + 1);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int mask = 0; mask < (1 << 10); mask++) {
      int newmask = masks[i] ^ (masks[i] & mask);
      dp[1][newmask] += dp[0][mask];
      if (dp[1][newmask] >= mod) {
        dp[1][newmask] -= mod;
      }
    }
    for (int mask = 0; mask < (1 << 10); mask++) {
      dp[0][mask] += dp[1][mask];
      if (dp[0][mask] >= mod) {
        dp[0][mask] -= mod;
      }
      dp[1][mask] = 0;
    }
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << 10); mask++) {
    if (__builtin_popcount(mask) >= k) {
      ans += dp[0][mask];
      if (ans >= mod) {
        ans -= mod;
      }
    }
  }
  fout << ans << "\n";
  return 0;
}