#include <iostream>
#include <fstream>

using namespace std;

struct Special {
  int l, r;
};

const int nmax = 1e5;
Special v[5 + nmax];
int n;
long long sum[5 + nmax];

static inline bool vcmp(Special a, Special b) {
  if (a.l == b.l)
    return a.r < b.r;
  return a.l < b.l;
}

int main() {
  ifstream fin("secvente.in");
  ofstream fout("secvente.out");
  fin >> n;
  for (int i = 1; i <= n; i++)
    fin >> v[i].l >> v[i].r;
  sort(v + 1, v + n + 1, vcmp);
  int p = 1;
  for (int i = 2; i <= n; i++) {
    while (p > 0 && v[p].r >= v[i].r)
      p--;
    v[++p] = v[i];
  }
  n = p;
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + 1ll * v[i].l * (v[i + 1].r - v[i].r);
  int t;
  fin >> t;
  while (t--) {
    int l, r;
    fin >> l >> r;
    int start = 0, st = 0, dr = n;
    while (st <= dr) {
      int mij = (st + dr) / 2;
      if (l > v[mij].l)
        st = mij + 1;
      else {
        start = mij;
        dr = mij - 1;
      } 
    }
    if (start == 0 || r < v[start].r) {
      fout << "0\n";
      continue;
    }
    int finish;
    st = start;
    dr = n;
    while (st <= dr) {
      int mij = (st + dr) / 2;
      if (r < v[mij].r)
        dr = mij - 1;
      else {
        finish = mij;
        st = mij + 1;
      }
    }
    long long ans = sum[finish - 1] - sum[start - 1];
    // pt start, scad ce am adunat in plus
    ans -= 1ll * (l - 1) * (r - v[start].r + 1);
    // caz special pt finish
    ans += 1ll * v[finish].l * (r - v[finish].r + 1);
    fout << ans << '\n';
  }
  return 0;
}
