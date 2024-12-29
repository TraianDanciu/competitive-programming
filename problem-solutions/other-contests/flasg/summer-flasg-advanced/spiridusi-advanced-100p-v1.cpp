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
  
  int p1 = 1;
  long long answer = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(a[i] == '1') {
      int p2 = p1;
      for(int j = n - 1; j >= 0; j--) {
        if(b[j] == '1') {
          answer += p2;
        }
        
        p2 <<= 1;
        if(p2 >= MOD) {
          p2 -= MOD;
        }
      }
    }
    
    p1 <<= 1;
    if(p1 >= MOD) {
      p1 -= MOD;
    }
  }
  
  cout << answer % MOD << "\n";
  return 0;
}
