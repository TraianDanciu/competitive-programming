#include <bits/stdc++.h>
#warning sunt pe onlinegdb

using namespace std;

const int nmax = 1e6;
long long a[5 + nmax], vmax[5 + nmax];

int main() {
    #ifdef ONLINE_JUDGE
        ifstream cin("divk.in");
        ofstream cout("divk.out");
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    // sa zicem ca secventa incepe la i + 1
    // eu vreau maximul dintre a[i + x * k]
    for (int i = n; i > n - k; i--) {
        vmax[i] = a[i];
    }
    for (int i = n - k; i >= 1; i--) {
        vmax[i] = max(a[i], vmax[i + k]);
    }
    long long ans = 0;
    for (int i = 0; i <= n - k; i++) {
        ans = max(ans, vmax[i + k] - a[i]);
    }
    cout << ans << '\n';
    return 0;
}
