#include <bits/stdc++.h>

#define notok { cout << "Impossible\n"; continue; }
#define Assert(val, okval) { if (val == -1) val = okval; else { if (val != okval) notok } }

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        string v[5];
        for (int i = 0; i < 5; i++)
            cin >> v[i];
        int value[5];
        for (int i = 0; i < 5; i++)
            if (v[i] == "?")
                value[i] = -1;
            else
            {
                value[i] = 0;
                for (int j = 0; j < v[i].size(); j++)
                    value[i] = value[i] * 10 + v[i][j] - '0';
            }
        if (value[1] == -1)
            if (value[2] == -1)
                if (value[3] == -1)
                {
                    if (value[4] == -1)
                        value[1] = value[2] = value[4] = 0;
                    else
                    {
                        if (value[4] % 3 + value[4] / 3 > value[0])
                            notok
                        value[1] = value[4] / 3;
                        value[2] = value[4] % 3;
                    }
                    value[3] = value[0] - value[1] - value[2];
                }
                else
                {
                    if (value[3] > value[0])
                        notok
                    if (value[4] == -1)
                    {
                        value[1] = 0;
                        value[4] = value[2] = value[0] - value[3];
                    }
                    else
                    {
                        if (value[4] < value[0] - value[3] || (value[4] - (value[0] - value[3])) % 2)
                            notok
                        value[1] = (value[4] - (value[0] - value[3])) / 2;
                        if (value[1] + value[3] > value[0])
                            notok
                        value[2] = value[0] - value[1] - value[3];
                    }
                }
            else
                if (value[3] == -1)
                {
                    if (value[2] > value[0])
                        notok
                    if (value[4] == -1)
                    {
                        value[4] = value[2];
                        value[1] = 0;
                    }
                    else
                    {
                        if (value[2] > value[4] || (value[4] - value[2]) % 3)
                            notok
                        value[1] = (value[4] - value[2]) / 3;
                        if (value[1] + value[2] > value[0])
                            notok
                    }
                    value[3] = value[0] - value[1] - value[2];
                }
                else
                {
                    if (value[2] + value[3] > value[0])
                        notok
                    value[1] = value[0] - value[2] - value[3];
                    Assert(value[4], value[1] * 3 + value[2])
                }
        else
            if (value[2] == -1)
                if (value[3] == -1)
                {
                    if (value[1] > value[0])
                        notok
                    if (value[4] == -1)
                    {
                        value[2] = 0;
                        value[3] = value[0] - value[1];
                        value[4] = value[1] * 3;
                    }
                    else
                    {
                        if (value[1] * 3 > value[4])
                            notok
                        value[2] = value[4] - value[1] * 3;
                        if (value[1] + value[2] > value[0])
                            notok
                        value[3] = value[0] - value[1] - value[2];
                    }
                }
                else
                {
                    if (value[1] + value[3] > value[0])
                        notok
                    value[2] = value[0] - value[1] - value[3];
                    Assert(value[4], value[1] * 3 + value[2])
                }
            else
            {
                Assert(value[4], value[1] * 3 + value[2])
                if (value[1] + value[2] > value[0] && value[3] == -1)
                    notok
                Assert(value[3], value[0] - value[1] - value[2])
            }
        for (int i = 0; i < 5; i++)
            cout << value[i] << ' ';
        cout << '\n';
    }
    return 0;
}
