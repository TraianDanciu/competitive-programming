#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
static inline int randgen(int left, int right) {
  return uniform_int_distribution<int>(left, right)(rng);
}

const int nmax = 10000;
int hsh[5 + nmax], a[5 + nmax], b[5 + nmax];
int prefa[5 + nmax], prefb[5 + nmax];
int suffa[5 + nmax], suffb[5 + nmax];

int main() {
  ifstream fin("mixperm.in");
  ofstream fout("mixperm.out");
  int n;
  fin >> n;
  int xr = 0;
  for (int i = 1; i <= n; i++)
    xr ^= (hsh[i] = randgen(1, 1000000000));
  for (int i = 1; i <= n; i++)
    fin >> a[i];
  for (int i = 1; i <= n; i++)
    fin >> b[i];
  // ca sa pot sa fac verificarea la xor hash in O(1)
  // imi trebuie niste "sume partiale" pt fiecare sir
  for (int i = 1; i <= n; i++) {
    prefa[i] = prefa[i - 1] ^ hsh[a[i]];
    prefb[i] = prefb[i - 1] ^ hsh[b[i]];
  }
  for (int i = n; i >= 1; i--) {
    suffa[i] = suffa[i + 1] ^ hsh[a[i]];
    suffb[i] = suffb[i + 1] ^ hsh[b[i]];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      int secva = prefa[j] ^ prefa[i - 1];
      int secvb = prefb[j] ^ prefb[i - 1];
      if ((prefa[i - 1] ^ secvb ^ suffa[j + 1]) == xr)
        ans++;
      else if ((prefb[i - 1] ^ secva ^ suffb[j + 1]) == xr)
        ans++;
    }
  fout << ans << '\n';
  return 0;
}
