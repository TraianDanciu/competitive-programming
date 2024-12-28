#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5, MOD = 1e9 + 7;
vector<pair<int, int>> g[5 + nmax];
int cnt[5 + nmax], n, viz[5 + nmax], depth[5 + nmax], nma[5 + nmax];
long long rez;

void dfs(int node, int parent) {
  cnt[node] = 1;
  viz[node] = 1;
  nma[node] = depth[node] = depth[parent] + 1;
  for(auto it : g[node]) {
    int son = it.first, cost = it.second;
    if(son != parent) {
      if(viz[son]) {
        nma[node] = min(nma[node], depth[son]);
      } else {
        dfs(son, node);
        nma[node] = min(nma[node], nma[son]);
        if(depth[node] < nma[son]) {
          rez = (rez + 1LL * cnt[son] * (n - cnt[son]) % MOD * cost) % MOD;
        }
        cnt[node] += cnt[son];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  dfs(1, 0);
  cout << rez << "\n";
  return 0;
}
