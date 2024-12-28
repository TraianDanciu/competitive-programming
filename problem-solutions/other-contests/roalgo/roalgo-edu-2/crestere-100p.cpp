#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0, prv = 0, ansi = 0;
  for(int i = 1; i <= n; i++) {
    int now;
    cin >> now;
    if(now - prv > ans) {
      ans = now - prv;
      ansi = i;
    }
    prv = now;
  }
  cout << ansi << "\n";
  return 0;
}
