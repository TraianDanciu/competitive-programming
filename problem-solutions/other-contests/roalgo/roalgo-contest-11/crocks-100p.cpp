#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int nmax = 1e6;
int a[5 + nmax], pref[5 + nmax], suff[5 + nmax], suff2[5 + nmax];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
    if(pref[i] >= MOD) {
      pref[i] -= MOD;
    }
  }
  for(int i = n; i > 0; i--) {
    suff[i] = (suff[i + 1] + 1LL * a[i] * pref[i - 1]) % MOD;
    suff2[i] = suff2[i + 1] + a[i];
    if(suff2[i] >= MOD) {
      suff2[i] -= MOD;
    }
  }
  
  int rez = 0;
  for(int i = 1; i <= n - 2; i++) {
    int now = suff[i + 2];
    now -= 1LL * pref[i] * suff2[i + 2] % MOD;
    if(now < 0) {
      now += MOD;
    }
    rez = (rez + 1LL * a[i] * now) % MOD;
  }
  cout << rez << "\n";
  return 0;
}
