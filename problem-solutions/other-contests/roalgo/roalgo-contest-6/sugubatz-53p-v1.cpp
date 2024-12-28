#include <bits/stdc++.h>

using namespace std;

const int VMAX = 1e6;
int freq[VMAX + 5], cnt[VMAX + 5], val[VMAX + 5];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 1; i <= VMAX; i++)
    {
        for (int j = i; j <= VMAX; j += i)
        {
            cnt[i] += freq[j];
        }
    }
    for (int i = 1; i <= VMAX; i++)
    {
        for (int j = i; j <= VMAX; j += i)
        {
            if (cnt[i] > 1)
            {
                val[j] = i;
            }
        }
    }
    vector<int> lg2(n + 1);
    lg2[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        lg2[i] = lg2[i >> 1] + 1;
    }
    vector<vector<int>> rmq(lg2[n] + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        rmq[0][i] = val[a[i]];
    }
    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            rmq[i][j] = (rmq[i - 1][j] | rmq[i - 1][j + (1 << (i - 1))]);
        }
    }
    function<int(int, int)> query = [&](int left, int right)
    {
        int lg = lg2[right - left + 1];
        return (rmq[lg][left] | rmq[lg][right - (1 << lg) + 1]);
    };
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = i, right = n, current = n + 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (query(i, middle) >= x)
            {
                right = middle - 1;
                current = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        ans += n - current + 1;
    }
    cout << ans;
    return 0;
}
