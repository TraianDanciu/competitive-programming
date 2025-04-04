#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e4;
int fr[4], dp2[2][6][6], dp3[2][6][6][6], dp4[2][6][6][6][6];

int main() {
  ifstream fin("ssce.in");
  ofstream fout("ssce.out");
  int n, b, k;
  fin >> n >> b >> k;
  if (b == 2) {
    for (int f0 = 0; f0 <= k; f0++)
      for (int f1 = 0; f1 <= k; f1++)
        dp2[0][f0][f1] = -1e9;
    dp2[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
      int val;
      fin >> val;
      fr[0] = fr[1] = 0;
      do {
        fr[val % 10]++;
        val /= 10;
      } while (val > 0);
      for (int f0 = 0; f0 <= k; f0++)
        for (int f1 = 0; f1 <= k; f1++) {
          dp2[i & 1][f0][f1] = dp2[(i - 1) & 1][f0][f1];
          if (f0 && f1)
            continue;
          int old0 = f0 - fr[0], old1 = f1 - fr[1], mn = min(old0, old1);
          old0 -= mn;
          old1 -= mn;
          if (old0 <= k && old1 <= k && dp2[(i - 1) & 1][old0][old1] != -1e9)
            dp2[i & 1][f0][f1] = max(dp2[i & 1][f0][f1], dp2[(i - 1) & 1][old0][old1] + 1);
        }
    }
    fout << dp2[n & 1][0][0] << '\n';
  } else if (b == 3) {
    for (int f0 = 0; f0 <= k; f0++)
      for (int f1 = 0; f1 <= k; f1++)
        for (int f2 = 0; f2 <= k; f2++)
          dp3[0][f0][f1][f2] = -1e9;
    dp3[0][0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
      int val;
      fin >> val;
      fr[0] = fr[1] = fr[2] = 0;
      do {
        fr[val % 10]++;
        val /= 10;
      } while (val > 0);
      for (int f0 = 0; f0 <= k; f0++)
        for (int f1 = 0; f1 <= k; f1++)
          for (int f2 = 0; f2 <= k; f2++) {
            dp3[i & 1][f0][f1][f2] = dp3[(i - 1) & 1][f0][f1][f2];
            if (f0 && f1 && f2)
              continue;
            int old0 = f0 - fr[0], old1 = f1 - fr[1], old2 = f2 - fr[2];
            int mn = min({old0, old1, old2});
            old0 -= mn;
            old1 -= mn;
            old2 -= mn;
            if (max({old0, old1, old2}) <= k)
              dp3[i & 1][f0][f1][f2] = max(dp3[i & 1][f0][f1][f2],
                                           dp3[(i - 1) & 1][old0][old1][old2] + 1);
          }
    }
    fout << dp3[0][0][0][0] << '\n';
  } else {

  }
  return 0;
}