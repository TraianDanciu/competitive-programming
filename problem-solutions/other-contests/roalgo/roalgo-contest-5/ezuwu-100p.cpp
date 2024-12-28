#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t;
    string s;
    cin >> n >> t >> s;
    s = "#" + s;
    vector<int> u(n + 1, 0), w(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        u[i] = u[i - 1];
        w[i] = w[i - 1];
        if (s[i] == 'u')
        {
            u[i]++;
        }
        else
        {
            w[i]++;
        }
    }
    while (t--)
    {
        int left, right;
        cin >> left >> right;
        cout << 1ll * (w[right] - w[left - 1]) * ((u[right] - u[left - 1] + 1) / 2) * ((u[right] - u[left - 1]) / 2) << '\n';
    }
    return 0;
}
