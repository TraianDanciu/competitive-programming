#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  string roalgo = "roalgo";
  int ans = 7;
  for(int i = 5; i < (int)s.size(); i++) {
    int cnt = 0;
    for(int j = 0; j < 6; j++) {
      cnt += roalgo[5 - j] != s[i - j];
    }
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
  return 0;
}
