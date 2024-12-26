#include <bits/stdc++.h>

using namespace std;

const int xmax = 1e6;
int fr[5 + xmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        fr[__gcd(x, y)]++;
    }
    int ans = 0;
    for (int i = xmax; i >= 1; i--)
    {
        int cnt = 0;
        for (int j = i; j <= xmax; j += i)
            cnt += fr[j];
        if (cnt >= k)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}
