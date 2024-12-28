#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int mod = 1e9 + 7;

void mult(int a[3][3], int b[3][3])
{
    int c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                c[i][j] += a[i][k] * b[k][j] % mod;
                if (c[i][j] >= mod)
                {
                    c[i][j] -= mod;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = c[i][j];
        }
    }
}

void init(int a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = (i == j);
        }
    }
}

void lgpow(int base[3][3], int exponent)
{
    int result[3][3];
    init(result);
    while (exponent)
    {
        if (exponent % 2)
        {
            mult(result, base);
        }
        mult(base, base);
        exponent /= 2;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            base[i][j] = result[i][j];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // dp[i][0] = numarul de numere cu i cifre care dau restul 0
    // dp[i][1] = ^ cu restul 1
    // dp[i][2] = ^ cu restul 2
    
    // dp[i][0] = 2 * dp[i - 1][0] + 1 * dp[i - 1][1] + 1 * dp[i - 1][2]
    // dp[i][1] = 1 * dp[i - 1][0] + 2 * dp[i - 1][1] + 1 * dp[i - 1][2]
    // dp[i][2] = 1 * dp[i - 1][0] + 1 * dp[i - 1][1] + 2 * dp[i - 1][2]
    
    // [dp[i - 1][0]]   [2 1 1]   [dp[i][0]]
    // [dp[i - 1][1]] * [1 2 1] = [dp[i][1]]
    // [dp[i - 1][2]]   [1 1 2]   [dp[i][2]]
    
    // dp[1][0] = 1
    // dp[2][0] = 1
    // dp[3][0] = 2
    
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[3][3] = {{2, 1, 1}, {1, 2, 1}, {1, 1, 2}};
        lgpow(a, n - 1);
        int b[3][3] = {{2, 1, 1}, {0, 0, 0}, {0, 0, 0}};
        mult(b, a);
        cout << b[0][x] << '\n';
    }
    return 0;
}
