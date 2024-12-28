#include <bits/stdc++.h>
#warning sunt pe onlinegdb

using namespace std;

const int nmax = 2e5;
int a[5 + nmax], sp[5 + nmax];

int main() {
    #ifdef ONLINE_JUDGE
        ifstream cin("flip.in");
        ofstream cout("flip.out");
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sp[i] = sp[i - 1] + (a[i] == 1 && a[i - 1] == 0);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sp[r] - sp[l - 1] + (a[l] == 1 && a[l - 1] == 1) << '\n';
    }
    return 0;
}
