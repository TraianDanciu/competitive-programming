#include "caesar.h"
#include <iostream>
#include <fstream>

using namespace std;

const int nmax = 1e6;
long long sum[nmax];
int stop[nmax];

void init(int n, int q, char a[], char b[]) {
  int len = 1;
  sum[0] = 1;
  for (int i = 1; i < n; i++) {
    int difcur = b[i] - a[i], difprv = b[i - 1] - a[i - 1];
    if (difcur < 0)
      difcur += 26;
    if (difprv < 0)
      difprv += 26;
    if (difcur == difprv)
      len++;
    else
      len = 1;
    sum[i] = sum[i - 1] + len;
  }
  stop[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    int difcur = b[i] - a[i], difnxt = b[i + 1] - a[i + 1];
    if (difcur < 0)
      difcur += 26;
    if (difnxt < 0)
      difnxt += 26;
    if (difcur == difnxt)
      stop[i] = stop[i + 1];
    else
      stop[i] = i;
  }
}

static inline long long gauss(int val) {
  return 1ll * val * (val + 1) / 2;
}

long long query(int left, int right) {
  if (stop[left] == stop[right])
    return gauss(right - left + 1);
  return gauss(stop[left] - left + 1) + sum[right] - sum[stop[left]];
}
