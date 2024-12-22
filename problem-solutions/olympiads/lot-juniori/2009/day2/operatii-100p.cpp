#include <bits/stdc++.h>

using namespace std;

const int vmax = 1e4, nmax = 200;
int dp[5 + vmax], nxt[5 + vmax], mat[5 + nmax][5 + nmax];

int main()
{
    ifstream cin("operatii.in");
    ofstream cout("operatii.out");
    for (int i = 1; i <= vmax; i++)
    {
        dp[i] = 1e9;
        for (int j = 1; j * j <= i; j++)
            if (dp[i] > dp[i - j * j] + 1)
            {
                dp[i] = dp[i - j * j] + 1;
                nxt[i] = j;
            }
    }
    int n, m;
    cin >> n >> m;
    int k = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            k = max(k, dp[mat[i][j]]);
        }
    cout << k << '\n';
    while (k--)
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << nxt[mat[i][j]] << ' ';
                mat[i][j] -= nxt[mat[i][j]] * nxt[mat[i][j]];
            }
            cout << '\n';
        }
    return 0;
}
