#include <bits/stdc++.h>

using namespace std;

const int VMAX = 1e6;
int a[VMAX + 5], freq[VMAX + 5], val[VMAX + 5], segtree[VMAX + 5];

void build(int node, int left, int right)
{
    if (left == right)
    {
        segtree[node] = val[a[left]];
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    segtree[node] = segtree[2 * node] | segtree[2 * node + 1];
}

int query(int node, int left, int right, int qleft, int qright)
{
    if (qleft <= left && right <= qright)
    {
        return segtree[node];
    }
    int middle = (left + right) / 2, ans = 0;
    if (qleft <= middle)
    {
        ans |= query(2 * node, left, middle, qleft, qright);
    }
    if (middle < qright)
    {
        ans |= query(2 * node + 1, middle + 1, right, qleft, qright);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 1; i <= VMAX; i++)
    {
        int sum = 0;
        for (int j = i; j <= VMAX; j += i)
        {
            sum += freq[j];
        }
        if (sum > 1)
        {
            for (int j = i; j <= VMAX; j += i)
            {
                val[j] = i;
            }
        }
    }
    build(1, 1, n);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = i, right = n, current = n + 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (query(1, 1, n, i, middle) >= x)
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
