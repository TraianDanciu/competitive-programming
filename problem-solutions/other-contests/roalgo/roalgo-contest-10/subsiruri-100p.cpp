#include <bits/stdc++.h>

using namespace std;

#define MAXLIT 26
#define MAXN 100000
#define MAXK 26
#define MOD 998244353

char a[MAXK + 1], b[MAXN + 1];
int k, poz[MAXLIT], dp[MAXK + 1][MAXK + 1], ans[MAXN + 1][MAXK + 1];
deque<pair<int, int>> queriesL[MAXN + 1], queriesR[MAXN + 1];

void divide(int st, int dr) {
  if(st == dr) {
    int answer = (k == 1 && b[st] == 1);
    while(!queriesL[st].empty() && queriesL[st].front().first == st) {
      ans[queriesL[st].front().second][0] = answer;
      queriesL[st].pop_front();
    }
  } else {
    int mij = (st + dr) / 2;
    
    // resetare
    for(int i = 0; i <= k; i++) {
      for(int j = i + 1; j <= k; j++) {
        dp[i][j] = 0;
      }
      
      dp[i][i] = 1;
    }
    
    for(int i = mij; i >= st; i--) {
      // adaug elementul i la sufix
      if(b[i] != 0) {
        for(int j = b[i]; j <= k; j++) {
          dp[b[i] - 1][j] += dp[b[i]][j];
          if(dp[b[i] - 1][j] >= MOD) {
            dp[b[i] - 1][j] -= MOD;
          }
        }
      }
      
      while(!queriesL[i].empty() && queriesL[i].back().first > mij) {
        for(int p = 0; p < k; p++) {
          ans[queriesL[i].back().second][p] = dp[0][p + 1];
        }
        
        queriesL[i].pop_back();
      }
    }
    
    // resetare
    for(int i = 0; i <= k; i++) {
      for(int j = i + 1; j <= k; j++) {
        dp[i][j] = 0;
      }
      
      dp[i][i] = 1;
    }
    
    for(int i = mij + 1; i <= dr; i++) {
      // adaug elementul i la prefix
      if(b[i] != 0) {
        for(int j = 0; j < b[i]; j++) {
          dp[j][b[i]] += dp[j][b[i] - 1];
          if(dp[j][b[i]] >= MOD) {
            dp[j][b[i]] -= MOD;
          }
        }
      }
      
    
      while(!queriesR[i].empty() && queriesR[i].front().first <= mij) {
        ans[queriesR[i].front().second][k] = dp[0][k];
        for(int p = 0; p < k; p++) {
          ans[queriesR[i].front().second][p] = 1LL * ans[queriesR[i].front().second][p] * dp[p + 1][k] % MOD;
        }
        
        queriesR[i].pop_front();
      }
    }
    
    divide(st, mij);
    divide(mij + 1, dr);
  }
}

void sortDeque(deque<pair<int, int>> &dq) {
  vector<pair<int, int>> v;
  while(!dq.empty()) {
    v.push_back(dq.front());
    dq.pop_front();
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < (int)v.size(); i++) {
    dq.push_back(v[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> k >> n;
  for(int i = 1; i <= k; i++) {
    cin >> a[i];
    poz[a[i] - 'a'] = i;
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] = poz[b[i] - 'a'];
  }
  
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    queriesL[l].emplace_back(r, i);
    queriesR[r].emplace_back(l, i);
  }
  
  for(int i = 1; i <= n; i++) {
    sortDeque(queriesL[i]);
    sortDeque(queriesR[i]);
  }
  divide(1, n);
  
  for(int i = 1; i <= q; i++) {
    int sol = 0;
    for(int j = 0; j <= k; j++) {
      sol += ans[i][j];
      if(sol >= MOD) {
        sol -= MOD;
      }
    }
    cout << sol << "\n";
  }
  
  return 0;
}
