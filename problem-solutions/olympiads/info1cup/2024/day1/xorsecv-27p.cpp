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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
        {
            ans += 1ll * lgpow(a[i] ^ j, p) * (n - i + 1) % mod;
            if (ans >= mod)
                ans -= mod;
        }
    cout << ans << '\n';
    return 0;
}
