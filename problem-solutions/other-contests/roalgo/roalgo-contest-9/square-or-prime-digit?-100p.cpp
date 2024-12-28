#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7')
            cnt++;
        else if (s[i] == '0' || s[i] == '1' || s[i] == '4' || s[i] == '9')
            cnt--;
    if (cnt > 0)
        cout << "Prime\n";
    else if (cnt < 0)
        cout << "Square\n";
    else
        cout << "Equal\n";
    return 0;
}
