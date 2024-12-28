/**
 * Problema Muxusetre
 * Autor: Traian Mihai Danciu
 * Autor cod: Traian Mihai Danciu
 * Sursa: RoAlgo Contest #7
**/

#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            char ch;
            cin >> ch;
        }
        int odd = n / 2 + n % 2, even = n / 2 + 1;
        long long ans = 1ll * odd * (odd - 1) / 2 + 1ll * even * (even - 1) / 2;
        cout << ans << '\n';
    }
    return 0;
}
