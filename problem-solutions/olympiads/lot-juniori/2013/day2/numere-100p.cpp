#include <bits/stdc++.h>

using namespace std;

int dp[5000];

int main() {
  ifstream fin("numere.in");
  ofstream fout("numere.out");
  int t, k;
  fin >> t >> k;
  map<int, int> mp;
  dp[0] = 1;
  for (int i = 1; i < k; i++) {
    dp[i] = 0;
    for (int j = 0; j < i; j++)
      dp[i] += dp[j];
    dp[i] %= 10;
  }
  int st, dr;
  for (int i = k; i < 5000; i++) {
    int nr = 0;
    dp[i] = 0;
    for (int j = i - k; j < i; j++) {
      nr = nr * 10 + dp[j];
      dp[i] += dp[j];
    }
    if (mp[nr]) {
      st = mp[nr];
      dr = i;
      break;
    }
    mp[nr] = i;
    dp[i] %= 10;
  }
  while (t--) {
    int s;
    fin >> s;
    fout << dp[s % (dr - st)] << ' ';
  }
  fout << '\n';
  return 0;
}