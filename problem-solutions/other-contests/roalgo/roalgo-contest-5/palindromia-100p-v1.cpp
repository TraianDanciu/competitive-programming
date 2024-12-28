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
    int x, freq[10] = {};
    cin >> x;
    int rev = 0, copy = x;
    while (copy) {
      rev = rev * 10 + copy % 10;
      copy /= 10;
    }
    if (rev == x)
      task1++;
    copy = x;
    do {
      freq[x % 10]++;
      totalfreq[x % 10]++;
      x /= 10;
    } while (x);
    int cnt = 0, cntdiff = 0;
    bool ok = false;
    for (int i = 0; i < 10; i++) {
      if (freq[i] == 0)
        continue;
      cntdiff++;
      cnt += freq[i] % 2;
      if (i && (freq[i] % 2 == 0 || (freq[i] % 2 && freq[i] >= 3)))
        ok = true;
    }
    ok |= cntdiff == 1;
    if (cnt <= 1 && ok) {
      task2++;
    }
  }
  int task3 = 0;
  for (int i = 1; i < 10; i++)
    task3 += totalfreq[i] / 2;
  cout << task1 << '\n' << task2 << '\n' << task3;
  return 0;
}
