/**
 * Problema: 3secv
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
        int val1 = -1, val2 = -1, val3 = -1, lst1 = 0, lst2 = 0, lst3 = 0, len = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x == val1)
            {
                lst1 = i;
                len++;
            }
            else if (x == val2)
            {
                lst2 = i;
                len++;
            }
            else if (x == val3)
            {
                lst3 = i;
                len++;
            }
            else if (val1 == -1)
            {
                val1 = x;
                lst1 = i;
                len++;
            }
            else if (val2 == -1)
            {
                val2 = x;
                lst2 = i;
                len++;
            }
            else if (val3 == -1)
            {
                val3 = x;
                lst3 = i;
                len++;
            }
            else
            {
                int mn = min({lst1, lst2, lst3});
                if (mn == lst1)
                {
                    len = i - lst1;
                    lst1 = i;
                    val1 = x;
                }
                else if (mn == lst2)
                {
                    len = i - lst2;
                    lst2 = i;
                    val2 = x;
                }
                else
                {
                    len = i - lst3;
                    lst3 = i;
                    val3 = x;
                }
            }
            ans = max(ans, len);
        }
        cout << ans << '\n';
    }
    return 0;
}
