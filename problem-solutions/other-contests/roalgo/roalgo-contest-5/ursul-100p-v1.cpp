/// Traian Mihai Danciu
/// RoAlgo Contest #5 - Back To School Edition
/// Problema ursul - autor Traian Mihai Danciu

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;

ll lgpow(ll base, ll exponent) {
  ll result = 1;
  while (exponent) {
    if (exponent % 2)
      result = result * base % mod;
    base = base * base % mod;
    exponent /= 2;
  }
  return result;
}

void solve() {
  ll n;
  cin >> n;
  cout << 3ll * (n % mod) % mod * lgpow(2, n - 1) % mod << '\n';
}

signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
