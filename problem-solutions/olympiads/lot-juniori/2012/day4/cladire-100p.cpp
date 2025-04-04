#include <bits/stdc++.h>

using namespace std;

const int mod = 666013, nmax = 1000;
int fact[5 + nmax + nmax], invfact[5 + nmax + nmax], dp[5 + nmax + nmax + nmax + nmax];

int lgpow(int base, int exponent)
{
    int result = 1;
    while (exponent)
    {
        if (exponent % 2)
            result = 1ll * result * base % mod;
        base = 1ll * base * base % mod;
        exponent /= 2;
    }
    return result;
}

void precalc(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = 1ll * fact[i - 1] * i % mod;
    invfact[n] = lgpow(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
        invfact[i] = 1ll * invfact[i + 1] * (i + 1) % mod;
}

int comb(int n, int k)
{
    if (n < 0 || k < 0 || n < k)
        return 0;
    return 1ll * fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

int h;

int get(int k)
{
    return comb((h - k) / 2 + k, (h - k) / 2);
}

signed main()
{
    ifstream cin("cladire.in");
    ofstream cout("cladire.out");
    int n;
    cin >> n >> h;
    precalc(h + h);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
        {
            if (i % 2 != h % 2 || j % 2 != h % 2 || i > h || j > h)
                continue;
            dp[i + j] += 1ll * get(i) * get(j) % mod;
            if (dp[i + j] >= mod)
                dp[i + j] -= mod;
        }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans += 1ll * dp[i] * dp[n - i] % mod;
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
    return 0;
}