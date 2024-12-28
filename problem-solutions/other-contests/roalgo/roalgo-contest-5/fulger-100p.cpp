#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    vector<long long> sums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sums[i] = sums[i - 1] + v[i];
    }
    int difmin = 1e6, lmin = 2e5;
    function<void(int, int)> check = [&](int left, int right)
    {
        if (v[right] - v[left] < difmin)
        {
            difmin = v[right] - v[left];
            lmin = right - left + 1;
        }
        else if (v[right] - v[left] == difmin)
        {
            lmin = min(lmin, right - left + 1);
        }
    };
    function<bool(int, int)> verify = [&](int left, int right)
    {
        return sums[right] - sums[left - 1] >= k;
    };
    for (int i = 1; i <= n; i++)
    {
        int left = i + 1, right = n, ans = i;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (verify(i, middle))
            {
                right = middle - 1;
                ans = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        if (i < ans)
        {
            check(i, ans);
        }
    }
    cout << difmin << ' ' << lmin;
    return 0;
}
