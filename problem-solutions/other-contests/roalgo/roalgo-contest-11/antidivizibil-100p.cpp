#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  cout << "2";
  for(int i = 2; i < n; i++) {
    cout << "0";
  }
  cout << "1\n";
  return 0;
}
