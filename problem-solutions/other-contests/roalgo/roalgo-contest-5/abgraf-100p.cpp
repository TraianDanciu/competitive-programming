#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        // atentie: urmeaza un cod relativ ciudat, nici nu stiu daca e bun
        int n, m;
        cin >> n >> m;
        vector<char> type(n + 1);
        int node_a = 0, node_b = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> type[i];
            if (type[i] == 'A')
            {
                node_a = i;
            }
            else
            {
                node_b = i;
            }
        }
        vector<vector<int>> g(n + 1);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> component(n + 1, 0);
        vector<bool> visited(n + 1, false);
        function<void(int, char, int)> dfs = [&](int u, char tp, int mark)
        {
            visited[u] = true;
            component[u] = mark;
            for (auto v : g[u])
            {
                if (!visited[v] && type[v] == tp)
                {
                    dfs(v, tp, mark);
                }
            }
        };
        int cnta = 0, cntb = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (type[i] == 'A')
                {
                    cnta++;
                    dfs(i, 'A', cnta);
                }
                else
                {
                    cntb++;
                    dfs(i, 'B', cntb);
                }
            }
        }
        if (cnta <= 1 || cntb <= 1)
        {
            cout << "DA\n";
            continue;
        }
        // cazul in care un nod din A se duce la B si A devine conex / invers
        vector<int> freqa(n + 1, 0), freqb(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (type[i] == 'A')
            {
                freqa[component[i]]++;
            }
            else
            {
                freqb[component[i]]++;
            }
        }
        if ((cnta == 2 && (freqa[1] == 1 || freqa[2] == 1)) || (cntb == 2 && (freqb[1] == 1 || freqb[2] == 1)))
        {
            cout << "DA\n";
            continue;
        }
        // cazul in care un nod din A se duce la B si B devine conex / invers
        bool ans = false;
        for (int i = 1; i <= n; i++)
        {
            set<int> components;
            for (auto it : g[i])
            {
                if (type[it] != type[i])
                {
                    components.insert(component[it]);
                }
            }
            int cnt;
            if (type[i] == 'A')
            {
                cnt = cntb;
            }
            else
            {
                cnt = cnta;
            }
            if (components.size() == cnt)
            {
                ans = true;
                break;
            }
        }
        if (ans)
        {
            cout << "DA\n";
            continue;
        }
        cout << "NU\n";
    }
    return 0;
}
