#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5;
int v[5 + nmax];

int main()
{
    ifstream cin("excursie.in");
    ofstream cout("excursie.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'L')
            v[i] = 0;
        else
            v[i] = 1;
        v[i] += v[i - 1];
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        int left, right;
        cin >> left >> right;
        if (left > right)
            swap(left, right);
        
        int ans = n + 1;
        if (v[right] - v[left - 1] == 0 || v[right] - v[left - 1] == right - left + 1)
            ans = 0;
        else
            for (int i = left - 1; i <= right; i++)
                ans = min(ans, (i - left + 1) - (v[i] - v[left - 1]) + (v[right] - v[i]));
        cout << ans << '\n';
    }
    
    return 0;
}
