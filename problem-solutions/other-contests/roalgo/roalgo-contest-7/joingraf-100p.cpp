/**
 * Problema: Joingraf
 * Autor: Traian Mihai Danciu
 * Autor cod: Traian Mihai Danciu
 * Sursa: RoAlgo Contest #7
**/

#include <bits/stdc++.h>

using namespace std;

namespace DSU
{
    vector<int> par, nxt;
    
    void init(int n)
    {
        par.resize(n + 1);
        nxt.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            nxt[i] = i + 1;
        }
    }
    
    int root(int u)
    {
        if (u == par[u])
        {
            return u;
        }
        return par[u] = root(par[u]);
    }
    
    void join(int u, int v)
    {
        u = root(u);
        v = root(v);
        if (u == v)
        {
            return;
        }
        par[v] = u;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    DSU::init(n);
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
        {
            int p = x;
            while (p <= y)
            {
                DSU::join(x, p);
                p = DSU::nxt[p];
            }
            DSU::nxt[x] = DSU::nxt[y];
        }
        else
        {
            if (DSU::root(x) == DSU::root(y))
            {
                cout << "Da\n";
            }
            else
            {
                cout << "Nu\n";
            }
        }
    }
    return 0;
}
