#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e5, mod = 1e9 + 7;
vector<int> graph[5 + nmax];
int status[5 + nmax];
bool ok;

void dfs(int node, int value)
{
    if (ok == false)
    {
        return;
    }
    status[node] = value;
    for (int son : graph[node])
    {
        if (status[son] == 0)
        {
            dfs(son, -value);
            if (ok == false)
            {
                return;
            }
        }
        else
        {
            if (status[son] == status[node])
            {
                ok = false;
                return;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ok = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (status[i] == 0)
        {
            cnt++;
            dfs(i, 1);
            if (ok == false)
            {
                break;
            }
        }
    }
    if (ok)
    {
        int ans = 1;
        for (int i = 1; i <= cnt; i++)
        {
            ans += ans;
            if (ans >= mod)
            {
                ans -= mod;
            }
        }
        cout << ans << '\n';
    }
    else
    {
        cout << "Doar carbuni\n";
    }
    for (int i = 1; i <= n; i++)
    {
        status[i] = 0;
        graph[i].clear();
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
