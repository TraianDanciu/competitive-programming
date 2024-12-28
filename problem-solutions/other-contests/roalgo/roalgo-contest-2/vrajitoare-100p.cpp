#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int NRCMAX = 1e5, mod = 1e9 + 7;
int fact[NRCMAX + 5], invfact[NRCMAX + 5], pw[15][NRCMAX + 5];

int lgpow(int base, int exponent) {
    int result = 1;
    while (exponent) {
        if (exponent % 2)
            result = result * base % mod;
        base = base * base % mod;
        exponent /= 2;
    }
    return result;
}

int invmod(const int &number) {
    return lgpow(number, mod - 2);
}

int combi(const int &n, const int &k) {
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

class Query {
    private:
        string number;
        int base, cnt_needed, ans;
        
        void reset() {
            ans = 0;
        }
        
        void read() {
            cin >> number >> base >> cnt_needed;
        }
        
        void add(const int &x, const int &y) {
            ans = (ans + combi(x, y) * pw[base - 1][x - y] % mod) % mod;
        }
        
        void solve() {
            if (cnt_needed <= number.size() - 1)
                add(number.size() - 1, cnt_needed);
            int cnt1 = 0;
            for (int position = 0; position < number.size(); position++) {
                for (int digit = 0; digit < number[position] - '0'; digit++) {
                    if (position == 0 && digit == 0)
                        continue;
                    if (cnt1 + (digit == 1) <= cnt_needed)
                        add(number.size() - position - 1, cnt_needed - (cnt1 + (digit == 1)));
                }
                if (number[position] == '1')
                    cnt1++;
                if (cnt1 > cnt_needed)
                    break;
            }
            if (cnt1 == cnt_needed)
                ans = (ans + 1) % mod;
            cout << ans << '\n';
        }
    
    public:
        Query() {
            reset(), read(), solve();
        }
};

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= NRCMAX; i++)
        fact[i] = fact[i - 1] * i % mod;
    for (int i = NRCMAX; i >= 1; i--)
        invfact[i] = invmod(fact[i]);
    for (int i = 1; i <= 9; i++) {
        pw[i][0] = 1;
        for (int j = 1; j <= NRCMAX + 5; j++)
            pw[i][j] = pw[i][j - 1] * i % mod;
    }
    int t = 1;
    cin >> t;
    while (t--)
        Query query;
    return 0;
}
