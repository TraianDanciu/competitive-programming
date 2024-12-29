#include <bits/stdc++.h>

using namespace std;

const int MOD = 1'000'741'823;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  string a, b;
  cin >> n >> a >> b;
  
  int ok = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i]) {
      a[i] = b[i] = '1';
    } else {
      if(ok) {
        a[i] = '0';
        b[i] = '1';
      } else {
        a[i] = '1';
        b[i] = '0';
        ok = 1;
      }
    }
  }
  
  int x = 0, y = 0, p = 1;
  for(int i = n - 1; i >= 0; i--) {
    if(a[i] == '1') {
      x += p;
      if(x >= MOD) {
        x -= MOD;
      }
    }
    
    if(b[i] == '1') {
      y += p;
      if(y >= MOD) {
        y -= MOD;
      }
    }
    
    p <<= 1;
    if(p >= MOD) {
      p -= MOD;
    }
  }
  
  cout << 1LL * x * y % MOD << "\n";
  return 0;
}
