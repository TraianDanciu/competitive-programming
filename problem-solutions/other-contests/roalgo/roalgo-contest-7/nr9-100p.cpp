/**
 * Problema: nr9
 * Autor: Matei Ionescu
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
    int n;
    cin >> n;
    if (n % 9 == 0)
    {
        cout << n - 1;
    }
    else
    {
        cout << n;
    }
    return 0;
}
