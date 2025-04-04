#include <bits/stdc++.h>

using namespace std;

const int nmax = 5e4;
int lmax[5 + nmax];

int get(int l, int r, string s) {
  while (s[l] == s[r]) {
    l--;
    r++;
  }
  return r - l - 1;
}

int main() {
  #ifdef KNOVA
    ifstream cin("secvpal.in");
    ofstream cout("secvpal.out");
  #endif
  int n, l;
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int m = s.size();
    s = "#" + s + "?";
    for (int j = 1; j <= m; j++) {
      lmax[i] = max(lmax[i], get(j, j, s));
      lmax[i] = max(lmax[i], get(j, j + 1, s));
    }
  }
  int s = 0, j = 1, cnt = 0;
  for (int i = 1; i <= n; i++) {
    s += lmax[i];
    while (s > l) {
      s -= lmax[j++];
    }
    if (s == l) {
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}