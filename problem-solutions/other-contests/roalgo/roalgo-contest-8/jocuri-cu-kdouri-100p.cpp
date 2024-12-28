#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int mod = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int p[2], n;
        for (int i = 0; i < 2; i++)
        {
            cin >> p[i];
        }
        cin >> n;
        int cnt = 0;
        for (int i = 2; i <= n + 1; i++)
        {
            if (p[i % 2] % i == 0)
            {
                cnt++;
            }
        }
        int ans = cnt, base = n, exponent = mod - 2;
        while (exponent)
        {
            if (exponent % 2)
            {
                ans = 1ll * ans * base % mod;
            }
            base = 1ll * base * base % mod;
            exponent /= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
