#include <bits/stdc++.h>

using namespace std;

#define MAXN 150000

int v[MAXN + 1], st[MAXN + 1], dr[MAXN + 1], timer;
vector<int> g[MAXN + 1], queries[MAXN + 1];

struct Query {
  int val, left, right, idx;
} qry[2 * MAXN + 1];
bool querycmp(Query a, Query b) {
  if(a.val == b.val) {
    return a.idx < b.idx;
  }
  return a.val < b.val;
}
int ans[2 * MAXN + 1];

struct Eulerpos {
  int node, idx;
} euler[2 * MAXN + 1];
bool eulercmp(Eulerpos a, Eulerpos b) {
  if(v[a.node] == v[b.node]) {
    return a.idx < b.idx;
  }
  return v[a.node] < v[b.node]; 
}

struct FenwickTree {
  int aib[2 * MAXN + 1], n;
  
  FenwickTree(int n) {
    this->n = n;
    for(int i = 0; i <= n; i++) {
      aib[i] = 0;
    }
  }
  
  FenwickTree() {}
  
  void update(int pos) {
    for(; pos <= n; pos += pos & -pos) {
      aib[pos]++;
    }
  } 
  
  int query(int pos) {
    int ans = 0;
    for(; pos > 0; pos &= pos - 1) {
      ans += aib[pos];
    }
    return ans;
  }
};

void dfs(int node, int parent) {
  st[node] = ++timer;
  euler[timer].node = node;
  euler[timer].idx = timer;
  
  for(int son : g[node]) {
    if(son != parent) {
      dfs(son, node);
    }
  }
  
  dr[node] = ++timer;
  euler[timer].node = node;
  euler[timer].idx = timer;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  dfs(1, 0);
  sort(euler + 1, euler + timer + 1, eulercmp);
  v[euler[timer + 1].node = 0] = 1e9 + 1;
  
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int node, l, r;
    cin >> node >> l >> r;
    
    qry[2 * i - 1].left = st[node];
    qry[2 * i - 1].right = dr[node];
    qry[2 * i - 1].val = l - 1;
    qry[2 * i - 1].idx = 2 * i - 1;
    
    qry[2 * i].left = st[node];
    qry[2 * i].right = dr[node];
    qry[2 * i].val = r;
    qry[2 * i].idx = 2 * i;
  }
  sort(qry + 1, qry + 2 * q + 1, querycmp);
  
  FenwickTree aib(timer);
  int ptr = 1;
  for(int i = 1; i <= 2 * q; i++) {
    while(v[euler[ptr].node] <= qry[i].val) {
      aib.update(euler[ptr++].idx);
    }
    ans[qry[i].idx] = aib.query(qry[i].right) - aib.query(qry[i].left - 1);
  }
  
  for(int i = 1; i <= q; i++) {
    cout << (ans[2 * i] - ans[2 * i - 1]) / 2 << "\n";
  }
  return 0;
}
