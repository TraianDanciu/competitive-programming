#include <bits/stdc++.h>

using namespace std;

#define MAXLIT 26
#define MAXN 100000
#define MAXK 5
#define MOD 998244353

char a[MAXK + 1], b[MAXN + 1];
int k, poz[MAXLIT];

struct SegmentTree {
  int n, dp[4 * MAXN + 1][MAXK + 1][MAXK + 1];
  
  void build(int node, int left, int right) {
    if(left == right) {
      if(b[left] != 0) {
        dp[node][b[left] - 1][b[left]] = 1;
      }
    } else {
      int middle = (left + right) / 2;
      build(2 * node, left, middle);
      build(2 * node + 1, middle + 1, right);
      
      for(int i = 0; i <= k; i++) {
        for(int j = i; j <= k; j++) {
          dp[node][i][j] = 0;
          for(int p = i; p <= j; p++) {
            dp[node][i][j] += 1LL * dp[2 * node][i][p] * dp[2 * node + 1][p][j] % MOD;
            if(dp[node][i][j] >= MOD) {
              dp[node][i][j] -= MOD;
            }
          }
        }
      }
    }
  }
  
  SegmentTree(int n) {
    for(int i = 0; i <= 4 * n; i++) {
      for(int j = 0; j <= k; j++) {
        for(int p = j + 1; p <= k; p++) {
          dp[i][j][p] = 0;
        }
        dp[i][j][j] = 1;
      }
    }
    
    this->n = n;
    build(1, 1, n);
  }
  
  int pref[MAXK + 1];
  
  void query(int node, int left, int right, int qleft, int qright) {
    if(qleft <= left && right <= qright) {
      // parcurgere inversa ca sa nu numar de mai multe ori
      for(int i = k; i >= 1; i--) {
        // vreau sa calculez pref[i]
        for(int j = 0; j < i; j++) {
          // pana la j am deja si adaug de la j
          pref[i] += 1LL * pref[j] * dp[node][j][i] % MOD;
          if(pref[i] >= MOD) {
            pref[i] -= MOD;
          }
        }
      }
    } else {
      int middle = (left + right) / 2;
      if(qleft <= middle) {
        query(2 * node, left, middle, qleft, qright);
      }
      if(middle < qright) {
        query(2 * node + 1, middle + 1, right, qleft, qright);
      }
    }
  }
  
  int query(int l, int r) {
    pref[0] = 1;
    for(int i = 1; i <= k; i++) {
      pref[i] = 0;
    }
    query(1, 1, n, l, r);
    return pref[k];
  }
};

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
  
  SegmentTree aint(n);
  
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    cout << aint.query(l, r) << "\n";
  }
  return 0;
}
