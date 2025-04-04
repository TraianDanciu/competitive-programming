#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax = 1e5;
pair<long long, long long> a[5 + nmax];

signed main() {
  ifstream fin("intervale.in");
  ofstream fout("intervale.out");
  int n, p;
  fin >> n >> p;
  for (int i = 1; i <= n; i++)
    fin >> a[i].first >> a[i].second;
  sort(a + 1, a + n + 1);
  int st = 0, dr = 14e8, ans = 14e8;
  while (st <= dr) {
    int mij = (st + dr) / 2, cnt = 1, ok = 0;
    for (int i = 2; i <= n; i++)
      if (a[i - 1].second + mij >= a[i].first - mij) {
        cnt++;
        if (cnt >= p)
          ok = 1;
      } else
        cnt = 1;
    if (ok) {
      ans = mij;
      dr = mij - 1;
    } else
      st = mij + 1;
  }
  fout << ans << '\n';
  return 0;
}