#include <bits/stdc++.h>

#define int long long

using namespace std;

struct matrix
{
    int mat[2][2];
    
    matrix()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
};

int mod;

matrix operator *(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c.mat[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c.mat[i][j] += 1ll * a.mat[i][k] * b.mat[k][j] % mod;
                if (c.mat[i][j] >= mod)
                {
                    c.mat[i][j] -= mod;
                }
            }
        }
    }
    return c;
}

matrix lgpow(matrix base, long long exponent)
{
    matrix result;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result.mat[i][j] = i == j;
        }
    }
    while (exponent)
    {
        if (exponent % 2)
        {
            result = result * base;
        }
        base = base * base;
        exponent /= 2;
    }
    return result;
}

int fib(long long n)
{
    matrix ans;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans.mat[i][j] = i || j;
        }
    }
    ans = lgpow(ans, n);
    return ans.mat[1][0];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r >> mod;
        // vrem fib[l] + fib[l + 1] + ... + fib[r]
        // stim ca fib[0] + fib[1] + ... + fib[n] = fib[n + 2] - 1
        // deci sumfib[l - 1] = fib[l + 1] - 1
        // iar sumfib[r] = fib[r + 2] - 1
        // deci raspunsul este fib[r + 2] - fib[l + 1]
        int ans = fib(r + 2) - fib(l + 1);
        if (ans < 0)
        {
            ans += mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
