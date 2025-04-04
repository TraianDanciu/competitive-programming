#include <bits/stdc++.h>

using namespace std;

const int mod = 666013, nmax = 50000;
int fact[5 + 2 * nmax], invfact[5 + 2 * nmax];

int comb(int n, int k) {
    if (n < k) return 0;
    return 1LL * fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

int lgpow(int a, int n) {
    int r = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) r = 1LL * r * a % mod;
        a = 1LL * a * a % mod;
    }
    return r;
}

int main()
{
    ifstream cin("implementare.in");
    ofstream cout("implementare.out");
    int k, n;
    cin >> k >> n;
    fact[0] = 1;
    for (int i = 1; i <= 2 * nmax; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
    invfact[2 * nmax] = lgpow(fact[2 * nmax], mod - 2);
    for (int i = 2 * nmax - 1; i >= 0; i--) invfact[i] = 1LL * invfact[i + 1] * (i + 1) % mod;
    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (1LL * i * comb(k - i + n - 1, n - 1) + ans) % mod;
    cout << ans << '\n';
    return 0;
}