#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--) {
    int n, words;
    string s;
    cin >> n >> words >> s;
    
    unordered_map<string, int> mp;
    while(words--) {
      string word;
      cin >> word;
      mp[word] = 1;
    }
    
    s = "#" + s;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
      string t = "";
      for(int j = i + 1; j <= n; j++) {
        t.push_back(s[j]);
        if(mp.count(t)) {
          dp[j] |= dp[i];
        }
      }
    }
    
    if(dp[n]) {
      cout << "DA\n";
    } else {
      cout << "NU\n";
    }
  }
  
  return 0;
}
