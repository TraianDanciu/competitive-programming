#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    int zero = 0, one = 0;
    long long ans = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        bool x;
        cin >> x;
        if (x)
        {
            one++;
        }
        else
        {
            zero++;
        }
        // a * u[right] - a * u[left - 1] - z[right] + z[left - 1] = b
        // a * u[right] - z[right] - (a * u[left - 1] - z[left - 1]) = b
        // a * u[right] - z[right] - b = a * u[left - 1] - z[left - 1]
        mp[a * one - zero]++;
        if (mp.count(a * one - zero - b))
        {
            ans += mp[a * one - zero - b];
        }
    }
    cout << ans;
    return 0;
}
