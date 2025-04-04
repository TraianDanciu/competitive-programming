#include <bits/stdc++.h>

using namespace std;

const int nmax = 5e5;
int a[5 + nmax];
long long sp[5 + nmax];

int main() {
  ifstream fin("cuie.in");
  ofstream fout("cuie.out");
  int n, m;
  fin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
    sp[i] = sp[i - 1] + a[i];
  }
  int dr = 0, cnt = 0, maxlen = 0;
  long long k = 1e9;
  deque<int> dq;
  for (int st = 1; st <= n; st++) {
    while (dr < n && sp[dr + 1] - sp[st - 1] -
          1ll * min(dq.empty() ? INT_MAX : a[dq.front()], a[dr + 1]) * (dr - st + 2) <= m) {
      dr++;
      while (!dq.empty() && a[dq.back()] > a[dr]) {
        dq.pop_back();
      }
      dq.push_back(dr);
    }
    if (dr - st + 1 > maxlen) {
      maxlen = dr - st + 1;
      k = sp[dr] - sp[st - 1] - 1ll * a[dq.front()] * (dr - st + 1);
    } else if (dr - st + 1 == maxlen) {
      k = min(k, sp[dr] - sp[st - 1] - 1ll * a[dq.front()] * (dr - st + 1));
    }
    while (!dq.empty() && dq.front() <= st) {
      dq.pop_front();
    }
  }
  fout << maxlen << " " << k << "\n";
  return 0;
}