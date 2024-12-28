#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5, LMAX = 100, mod = 1e9 + 7;
vector<int> g[NMAX + 1], topsort;
int dp[NMAX + 1][LMAX + 1], l;
bitset<NMAX + 1> visited;

#define int long long 

void dfs(const int &u) {
    visited[u] = true;
    for (auto v : g[u])
        if (!visited[v])
            dfs(v);
    topsort.push_back(u);
}

int lgpow(int base, int exponent) {
    int result = 1;
    while (exponent) {
        if (exponent % 2)
            result = result * base % mod;
        base = base * base % mod;
        exponent /= 2;
    }
    return result;
}

int invmod(const int &number) {
    return lgpow(number, mod - 2);
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n, m, u, v;
    cin >> n >> m >> l;
    for (int i = 1; i <= m; i++)
        cin >> u >> v, g[u].push_back(v);
	topsort.push_back(0);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
    for (int i = n; i >= 1; i--) {
        int u = topsort[i];
        dp[u][0] = 1;
        for (auto v : g[u])
            for (int i = 0; i < l; i++)
                dp[v][i + 1] = (dp[v][i + 1] + dp[u][i]) % mod;
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= l; j++)
            a = (a + dp[i][j]) % mod;
    for (int j = 0; j <= l; j++)
        b = (b + dp[n][j]) % mod;
    cout << b * invmod(a) % mod;
    return 0;
}
