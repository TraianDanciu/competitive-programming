#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g, inv;
vector<int> dist, ans;
int k, n;

void dfs1(int u) {
    for (auto v : inv[u])
        if (dist[v] == 0)
            dist[v] = dist[u] + 1, dfs1(v);
}

void dfs2(int u) {
    ans.push_back(u);
    if (u == k)
        return;
    int minimum = n + 1;
    for (auto v : g[u])
        if (dist[v])
            minimum = min(minimum, v);
    dfs2(minimum);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int m;
    cin >> n >> m >> k;
    g.resize(n + 1);
    inv.resize(n + 1);
    dist.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        inv[v].push_back(u);
    }
    dist[k] = 1;
    dfs1(k);
    int first = n + 1;
    for (int i = 1; i <= n; i++)
        if (dist[i]) {
            first = i;
            break;
        }
    dfs2(first);
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << ' ';
    return 0;
}
