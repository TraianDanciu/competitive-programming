#include <bits/stdc++.h>
#warning sunt pe onlinegdb

using namespace std;

const int nmax = 2e5;
int a[5 + nmax], b[5 + nmax], spa[5 + nmax][26], spb[5 + nmax][26];

int main() {
    #ifdef ONLINE_JUDGE
        ifstream cin("matmare.in");
        ofstream cout("matmare.out");
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int bit = 0; bit < 26; bit++) {
            spa[i][bit] = spa[i - 1][bit] + ((a[i] >> bit) & 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        for (int bit = 0; bit < 26; bit++) {
            spb[i][bit] = spb[i - 1][bit] + ((b[i] >> bit) & 1);
        }
    }
    while (q--) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        long long ans = 0;
        int nra = a2 - a1 + 1, nrb = b2 - b1 + 1;
        for (int bit = 0; bit < 26; bit++) {
            int catea = spa[a2][bit] - spa[a1 - 1][bit];
            int cateb = spb[b2][bit] - spb[b1 - 1][bit];
            ans += (1ll << bit) * (1ll * catea * nrb + 1ll * cateb * nra - 1ll * catea * cateb);
        }
        cout << ans << '\n';
    }
    return 0;
}
