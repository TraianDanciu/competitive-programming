#include <iostream>

using namespace std;

using ll = long long;

const int nmax = 2e5, vmax = 1 << 20, mod = 1e9 + 7;
int a[5 + nmax], fr[5 + vmax];

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0, lst = 0;
    for (int i = 20; i >= 0; i--) {
        for (int j = 1; j < (1 << i); j++) 
            fr[j] = 0;
        fr[0] = 1;
        int sum = 0;
        ll crt = 0;
        for (int j = 1; j <= n; j++) {
            sum += a[j];
            sum &= (1 << i) - 1;
            crt += fr[sum];
            fr[sum]++;
        }
        ans += 1ll * (crt - lst) % mod * (1 << i) % mod;
        if (ans >= mod)
            ans -= mod;
        lst = crt;
    }
    cout << ans << '\n';
    return 0;
}
