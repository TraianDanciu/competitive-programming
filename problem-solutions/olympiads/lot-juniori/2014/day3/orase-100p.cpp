#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e6;
int v[5 + nmax], n, k, nro;

int check(long long val) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j <= n && v[j] - v[i] <= val)
      j++;
    j--;
    int p = j;
    while (p <= n && v[p] - v[j] <= val)
      p++;
    i = p - 1;
    cnt++;
  }
  nro = cnt;
  return (cnt <= k);
}

int main() {
  ifstream fin("orase.in");
  ofstream fout("orase.out");
  fin >> n >> k;
  for (int i = 2; i <= n; i++) {
    fin >> v[i];
    v[i] += v[i - 1];
  }
  long long st = 0, dr = 1e18, ans = 1e18;
  while (st <= dr) {
    long long mij = (st + dr) / 2;
    if (check(mij)) {
      ans = mij;
      dr = mij - 1;
    } else
      st = mij + 1;
  }
  check(ans);
  fout << ans << ' ' << nro << '\n';
  return 0;
}