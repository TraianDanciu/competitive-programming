#include <bits/stdc++.h>

using namespace std;

const int vmax = 2e5;
int dp[5 + vmax];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v;
    cin >> n >> v;
    dp[v] = n;
    for (int i = 1; i <= v; i++)
    {
        int z;
        cin >> z;
        dp[v ^ i] = n - z;
    }
    for (int bit = 0; bit < 18; bit++)
    {
        for (int i = v; i >= 1; i--)
        {
            if (i & (1 << bit))
            {
                dp[i] -= dp[i ^ (1 << bit)];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (dp[i] < 0)
        {
            cout << "-1\n";
            return 0;
        }
        cnt += dp[i];
    }
    if (cnt == n)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= dp[i]; j++)
            {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}
