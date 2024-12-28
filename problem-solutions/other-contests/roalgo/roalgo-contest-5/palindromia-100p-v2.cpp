/// Traian Mihai Danciu
/// RoAlgo Contest #5 - Back To School
/// Palindromia - autor Stefan Cosmin Dascalescu

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int task1 = 0, task2 = 0, totalfreq[10] = {};
  while (n--) {
    int freq[10] = {};
    string x;
    cin >> x;
    string rev = x;
    reverse(rev.begin(), rev.end());
    if (rev == x)
      task1++;
    for (char ch : x) {
      freq[ch - '0']++;
      totalfreq[ch - '0']++;
    }
    int cnt = 0, cntdiff = 0;
    for (int i = 0; i < 10; i++) {
      if (freq[i] == 0)
        continue;
      if (i)
        cntdiff += freq[i];
      cnt += freq[i] % 2;
    }
    if (cnt <= 1 && cntdiff >= 2)
      task2++;
  }
  int task3 = 0;
  for (int i = 1; i < 10; i++)
    task3 += totalfreq[i] / 2;
  cout << task1 << '\n' << task2 << '\n' << task3;
  return 0;
}
