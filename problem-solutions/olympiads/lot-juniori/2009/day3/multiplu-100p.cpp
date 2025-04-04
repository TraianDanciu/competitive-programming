#include <bits/stdc++.h>

using namespace std;

const int mod = 10000;

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
    ifstream cin("multiplu.in");
    ofstream cout("multiplu.out");
    int k, n;
    cin >> n >> k;
    int d = 2, ans = 1;
    while (d * d <= n)
    {
        if (n % d == 0)
        {
            int e = 0;
            do  
            {
                e++;
                n /= d;
            }
            while (n % d == 0);
            ans = 1LL * ans * (lgpow(e + 1, k) - lgpow(e, k)) % mod;
            if (ans < 0)
                ans += mod;
        }
        d++;
    }
    if (n > 1)
        ans = 1LL * ans * (lgpow(2, k) - 1) % mod;
    cout << ans << '\n';
    return 0;
}