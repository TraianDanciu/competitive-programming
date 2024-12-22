#include <iostream>
#include <fstream>

using namespace std;

const int vmax = 80000, nmax = 16;
int has[5 + vmax], cnt[1 << nmax];

int main() {
  ifstream fin("barliga.in");
  ofstream fout("barliga.out");
  int n, v;
  fin >> n >> v;
  for (int i = 0; i < n; i++) {
    int k;
    fin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      fin >> x;
      has[x] |= 1 << i;
    }
  }
  // vreau sa vad in toate configuratiile care este minimul de valori invizibile
  // si pentru care configuratie se obtine acest minim de valori invizibile
  // si de aia numar de cate ori apare fiecare nr in has[] (pt ca daca nu facem)
  // cu exact masca aia, un bit va ramana sau se va transofrma din 0 in 1
  for (int i = 1; i <= v; i++)
    cnt[has[i]]++;
  // si atunci mie imi trebuie minimul din cnt si pentru ce se obtine minim
  int vmin = 0;
  for (int i = 1; i < (1 << n); i++)
    if (cnt[i] < cnt[vmin])
      vmin = i;
  fout << v - cnt[vmin] << '\n' << __builtin_popcount(vmin);
  for (int i = 0; i < n; i++)
    if (vmin & (1 << i))
      fout << ' ' << i + 1;
  fout << '\n';
  return 0;
}
