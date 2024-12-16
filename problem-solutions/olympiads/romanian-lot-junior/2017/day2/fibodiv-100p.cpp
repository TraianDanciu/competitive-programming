#include <iostream>
#include <fstream>

using namespace std;

const int nmax = 15, vmax = 50;
int a[5 + nmax], mult[5 + vmax];

long long mygcd(long long a, long long b) {
  while (b) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}

static inline long long mylcm(long long a, long long b) {
  return a / mygcd(a, b) * b;
}

int main() {
  ifstream fin("fibodiv.in");
  ofstream fout("fibodiv.out");
  for (int i = 2; i <= 50; i++) {
    int a = 1, b = 1, c;
    mult[i] = 2;
    while (true) {
      mult[i]++;
      c = (a + b) % i;
      a = b;
      b = c;
      if (c == 0)
        break;
    }
  }
  int n;
  long long t;
  fin >> n >> t;
  for (int i = 1; i <= n; i++)
    fin >> a[i];
  long long ans = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    long long l = 1;
    int elem = 0;
    for (int i = 1; i <= n; i++)
      if (mask & (1 << (i - 1))) {
        l = mylcm(l, mult[a[i]]);
        elem++;
      }
    // pinexul spune ca la cele cu nr par de elemente scad
    // si la cele cu nr impar de elemente adun
    if (elem % 2)
      ans += t / l;
    else
      ans -= t / l;
  }
  fout << ans << '\n';
  return 0;
}
