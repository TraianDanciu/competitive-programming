/**
 * Problema: divnr
 * Autor: Traian Mihai Danciu
 * Autor cod: Traian Mihai Danciu
 * Sursa: RoAlgo Contest #7
**/

#include <bits/stdc++.h>

using namespace std;

int __lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int lcm = 1;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            lcm = __lcm(lcm, x);
        }
        cout << lcm;
        int digits = 0;
        do
        {
            digits++;
            lcm /= 10;
        }
        while (lcm);
        for (int i = digits + 1; i <= m; i++)
        {
            cout << "0";
        }
        cout << '\n';
    }
    return 0;
}
