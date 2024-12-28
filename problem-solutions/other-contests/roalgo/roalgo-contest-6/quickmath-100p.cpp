#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt_n = 0, cnt_2n = 0, cnt_minus_n = 0, cnt_minus_2n = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x == n)
            {
                cnt_n++;
            }
            else if (x == -n)
            {
                cnt_minus_n++;
            }
            else if (x == 2 * n)
            {
                cnt_2n++;
            }
            else if (x == -2 * n)
            {
                cnt_minus_2n++;
            }
        }
        if (cnt_n >= 2 && cnt_minus_2n >= 1)
        {
            cout << "DA\n";
        }
        else if (cnt_minus_n >= 2 && cnt_2n >= 1)
        {
            cout << "DA\n";
        }
        else
        {
            cout << "NU\n";
        }
    }
    return 0;
}
