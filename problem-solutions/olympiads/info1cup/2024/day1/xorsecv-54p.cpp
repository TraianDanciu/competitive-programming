#include <bits/stdc++.h>

using namespace std;

const int nmax = 25e4;
int a[5 + nmax];

const int mod = 1e9 + 7;
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

int pref[8][5 + nmax]; // pref[i][j] = lgpow(i ^ 0, p) + lgpow(i ^ 1, p) + .. + lgpow(i ^ j, p)
int bitpref[18][1 << 18]; // bitpref[i][j] = de cate ori apare bitul i in numerele de la 0 la j

void precalc(int p, int n)
{
    for (int i = 0; i < 8; i++)
    {
        pref[i][0] = lgpow(i, p);
        for (int j = 1; j <= n; j++)
        {
            pref[i][j] = pref[i][j - 1] + lgpow(i ^ j, p);
            if (pref[i][j] >= mod)
                pref[i][j] -= mod;
        }
    }
    for (int i = 0; i < 18; i++)
        for (int j = 1; j < (1 << 18); j++)
            bitpref[i][j] = bitpref[i][j - 1] + ((j >> i) & 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> n >> p;
    int amax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
    int ans = 0;
    if (amax < 8)
    {
        precalc(p, n);
        for (int i = 1; i <= n; i++)
        {
            ans += 1ll * pref[a[i]][i - 1] * (n - i + 1) % mod;
            if (ans >= mod)
                ans -= mod;
        }
    }
    else if (p == 1)
    {
        precalc(p, n);
        for (int i = 1; i <= n; i++)
        {
            // fiecare bit, de cate ori apare 
            int sum = 0;
            for (int bit = 0; bit < 18; bit++)
            {
                if (a[i] & (1 << bit))
                    sum += (1ll << bit) * (i - bitpref[bit][i - 1]) % mod;
                else
                    sum += (1ll << bit) * bitpref[bit][i - 1] % mod;
                if (sum >= mod)
                    sum -= mod;
            }
            ans += 1ll * sum * (n - i + 1) % mod;
            if (ans >= mod)
                ans -= mod;
        }
    }
    /*
    else if (p == 2)
    {
        
    }
    */
    else
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            for (int j = 0; j < i; j++)
            {
                sum += lgpow(a[i] ^ j, p);
                if (sum >= mod)
                    sum -= mod;
            }
            ans += 1ll * sum * (n - i + 1) % mod;
            if (ans >= mod)
                ans -= mod;
        }
    cout << ans << '\n';
    return 0;
}
