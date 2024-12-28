#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int NMAX = 5e3;
int fact[NMAX + 5], invfact[NMAX + 5], mod, dp[NMAX + 5];

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

int comb(const int &n, const int &k) {
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n;
    cin >> n >> mod;
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n + 1; i++)
        fact[i] = fact[i - 1] * i % mod;
    invfact[n + 1] = invmod(fact[n + 1]);
    for (int i = n; i >= 1; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    int ans = 1;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++)
            dp[i] = (dp[i] + dp[j] * dp[i - j - 1] % mod * comb(i - 1, j)) % mod;
        dp[i] = (dp[i] * invfact[2]) % mod;
        ans = (ans + dp[i]) % mod;
    }
    cout << ans;
    return 0;
}
