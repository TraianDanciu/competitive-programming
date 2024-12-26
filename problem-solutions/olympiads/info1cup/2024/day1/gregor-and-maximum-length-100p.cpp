#include <bits/stdc++.h>

using namespace std;

const int nmax = 200000;
pair<int, int> a[5 + nmax];
int aib[5 + nmax], n;

void update(int pos, int val)
{
    for (int i = pos; i <= n; i += i & -i)
        aib[i] = max(aib[i], val);
}

int query(int pos)
{
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i)
        ans = max(ans, aib[i]);
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int i = 1, ans = 0;
    while (i <= n)
    {
        int j = i;
        while (j <= n && a[j].first == a[i].first)
            j++;
        j--;
        int dp = j - i + 1 + query(a[i].second - 1);
        ans = max(ans, dp);
        update(a[j].second, dp);
        i = j + 1;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        aib[i] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}
