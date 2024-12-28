#include <bits/stdc++.h>

using namespace std;

int prim(int n) {
  if(n == 2 || n == 3) {
    return 1;
  }
  if(n % 2 == 0 || n % 3 == 0) {
    return 0;
  } 
  for(int d = 5; d * d <= n; d += 6) {
    if(n % d == 0) {
      return 0;
    }
    if(n % (d + 2) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  freopen("neprim.in", "r", stdin);
  freopen("neprim.out", "w", stdout);
  int n, cnt;
  cin >> n;
  cnt = 0;
  for(int i = 1; i <= n; i++) {
    int val;
    cin >> val;
    if(prim(val) == 0) {
      int ok = 1;
      while(val > 0) {
        if(val % 10 != 2 && val % 10 != 3 && val % 10 != 5 && val % 10 != 7) {
          ok = 0;
        }
        val /= 10;
      }
      cnt += ok;
    }
  }
  cout << cnt << "\n";
  return 0;
}
