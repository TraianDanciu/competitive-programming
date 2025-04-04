#include <bits/stdc++.h>

using namespace std;

const int nmax = 1000;
int perm[5 + nmax];

int main() {
  ifstream fin("partitie.in");
  ofstream fout("partitie.out");
  int n;
  fin >> n;
  int p = 0;
  for (int i = 1; i <= n; i += 2)
    perm[++p] = i;
  for (int i = 2; i <= n; i += 2)
    perm[++p] = i;
  for (int i = 1; i <= n; i++) {
    int p = i;
    for (int j = 1; j <= n; j++) {
      fout << perm[p] + n * (j - 1) << ' ';
      p = p % n + 1;
    }
    fout << '\n';
  }
  return 0;
}