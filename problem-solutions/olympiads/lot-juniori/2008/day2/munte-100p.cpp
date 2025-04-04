#include <bits/stdc++.h>

using namespace std;

const int nmax = 64000, mod = 12343;
int a[5 + nmax], fr[5 + nmax];

signed main()
{
    ifstream fin("munte.in");
    ofstream fout("munte.out");
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
        fr[a[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= nmax; i++)
    {
        if (fr[i] > 2)
        {
            fout << "0\n";
            return 0;
        }
        if (fr[i] == 1)
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        fout << "0\n";
        return 0;
    }
    int ans = 1;
    for (int i = 1; i < cnt; i++)
    {
        ans += ans;
        if (ans >= mod)
        {
            ans -= mod;
        }
    }
    if (cnt == n)
    {
        ans -= 2;
        if (ans < 0)
        {
            ans += mod;
        }
    }
    fout << ans << '\n';
    return 0;
}