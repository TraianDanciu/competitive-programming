#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        if (a % b == 0)
        {
            if (b == 1)
                cout << "1 " << a << '\n';
            else
                cout << "2 " << a / b << ' ' << a * b << '\n';
        }
        else
            cout << "0\n";
    }
    return 0;
}
