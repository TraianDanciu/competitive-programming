#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4'000'000;
int first_app[MAXN + 1], last_app[MAXN + 1];
long long sum[MAXN + 1];

// first_app[i] is the first appearence of an 1 after i
// last_app[i] is the last appearence of an 1 before i

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  string s;
  cin >> n >> s;
  s = "#" + s;
  
  for(int i = 1; i <= n; i++) {
    if(s[i] == '1') last_app[i] = i;
    else last_app[i] = last_app[i - 1];
    sum[i] = sum[i - 1] + last_app[i];
  }
  for(int i = n; i >= 1; i--) {
    if(s[i] == '1') first_app[i] = i;
    else first_app[i] = first_app[i + 1];
  }
  
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    
    if(last_app[r] < l) cout << "0\n";
    else cout << (sum[r] - sum[first_app[l] - 1]) - 1LL * (l - 1) * (r - first_app[l] + 1) << "\n";
  }
  
  return 0;
}
