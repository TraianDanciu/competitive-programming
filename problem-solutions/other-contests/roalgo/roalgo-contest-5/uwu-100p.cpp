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
    vector<int> l(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        l[i] = l[i - 1] + (s[i] == 'u');
    }
    vector<int> r(n + 2, 0);
    for (int i = n; i >= 1; i--)
    {
        r[i] = r[i + 1] + (s[i] == 'u');
    }
    vector<long long> sum_l(n + 1, 0), sum_r(n + 1, 0), mult(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        sum_l[i] = sum_l[i - 1];
        sum_r[i] = sum_r[i - 1];
        mult[i] = mult[i - 1];
        cnt[i] = cnt[i - 1];
        if (s[i] == 'w')
        {
            sum_l[i] += l[i];
            sum_r[i] += r[i];
            mult[i] += 1ll * l[i] * r[i];
            cnt[i]++;
        }
    }
    while (t--)
    {
        int left, right;
        cin >> left >> right;
        long long multsum = mult[right - 1] - mult[left];
        long long rleft = 1ll * r[right + 1] * (sum_l[right - 1] - sum_l[left]);
        long long lright = 1ll * l[left - 1] * (sum_r[right - 1] - sum_r[left]);
        long long sumlr = 1ll * l[left - 1] * r[right + 1] * (cnt[right - 1] - cnt[left]);
        cout << multsum - rleft - lright + sumlr << '\n';
    }
    return 0;
}
