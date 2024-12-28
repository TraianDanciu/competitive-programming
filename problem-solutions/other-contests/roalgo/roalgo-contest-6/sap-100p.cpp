#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define MAXN 500000

vector<int> g[MAXN + 1];
int v[MAXN + 1], subtreeSize[MAXN + 1], hsh[MAXN + 1], subtreeHash[MAXN + 1];

void dfs(int node, int parent) {
  subtreeSize[node] = 1;
  subtreeHash[node] = v[node];
  
  for(int son : g[node]) {
    if(son != parent) {
      dfs(son, node);
      subtreeSize[node] += subtreeSize[son];
      subtreeHash[node] ^= subtreeHash[son];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    hsh[i] = uniform_int_distribution<int>(0, 1e9)(rng);
  }
  
  for(int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] = hsh[v[i]];
  }
  
  for(int i = 1; i <= n; i++) {
    hsh[i] ^= hsh[i - 1]; // hsh[i] = hashul unei permutari
  }
  
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  
  int q;
  cin >> q;
  while(q--) {
    int node;
    cin >> node;
    if(subtreeHash[node] == hsh[subtreeSize[node]]) {
      cout << "DA\n";
    } else {
      cout << "NU\n";
    }
  }
  
  return 0;
}
