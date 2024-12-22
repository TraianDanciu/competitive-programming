#include <bits/stdc++.h>

#define int long long

using namespace std;

const int nmax = 50000;
int a[5 + nmax];

bool verify(int k, int n, int p)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < k)
        {
            sum += k - a[i];
        }
    }
    if (sum > p)
    {
        return false;
    }
    if (sum > k)
    {
        return false;
    }
    return true;
}

signed main()
{
    ifstream fin("tabara.in");
    ofstream fout("tabara.out");
    int n, p;
    fin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int left = 1, right = nmax, ans = 0;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (verify(middle, n, p))
        {
            left = middle + 1;
            ans = middle;
        }
        else
        {
            right = middle - 1;
        }
    }
    fout << ans << '\n';
    return 0;
}
