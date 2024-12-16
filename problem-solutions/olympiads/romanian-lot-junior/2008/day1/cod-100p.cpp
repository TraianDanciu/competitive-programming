#include <bits/stdc++.h>

using namespace std;

const int mod = 9901;
int fr[26];

int lgpow(int base, int exponent)
{
    int result = 1;
    while (exponent)
    {
        if (exponent % 2)
        {
            result = 1ll * result * base % mod;
        }
        base = 1ll * base * base % mod;
        exponent /= 2;
    }
    return result;
}

signed main()
{
    ifstream fin("cod.in");
    ofstream fout("cod.out");
    int n;
    string s;
    int ans = 0;
    fin >> n >> s;
    for (char ch : s)
    {
        fr[ch - 'a']++;
    }
    // I: toate distincte
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (fr[i])
        {
            cnt++;
        }
    }
    int fact = 1;
    if (cnt >= n)
    {
        // aranj(cnt, n)
        for (int i = cnt; i > cnt - n; i--)
        {
            fact = 1ll * fact * i % mod;
        }
        ans += fact;
    }
    // II: una se repeta
    int cntr = 0;
    for (int i = 0; i < 26; i++)
    {
        if (fr[i] > 1)
        {
            cntr++;
        }
    }
    // se poate repeta pe n * (n - 1) / 2 perechi
    // raman n - 2 pe care sa punem 
    if (cnt >= n - 2)
    {
        cnt--;
        // aranj(cnt, n - 2) * n * (n - 1) / 2
        fact = 1;
        for (int i = cnt; i > cnt - (n - 2); i--)
        {
            fact = 1ll * fact * i % mod;
        }
        fact = 1ll * fact * n % mod;
        fact = 1ll * fact * (n - 1) % mod;
        fact = 1ll * fact * lgpow(2, mod - 2) % mod;
        fact = 1ll * fact * cntr % mod;
        ans += fact;
        if (ans >= mod)
        {
            ans -= mod;
        }
    }
    fout << ans << '\n';
    return 0;
}
