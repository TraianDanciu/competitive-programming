#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back

using namespace std;

ll number(int idx, int base) {
    ll pwr = 1, ans = 0;
    while (idx) {
        if (idx % 2)
            ans += pwr;
        idx /= 2;
        pwr *= base;
    }
    return ans;
}

signed main() {
  	#ifndef TEST 
    		freopen("puteri35.in", "r", stdin);
    		freopen("puteri35.out", "w", stdout);
  	#endif
  	ios_base :: sync_with_stdio(false);
  	cin.tie(nullptr);
  	cout.tie(nullptr);
	
    int i = 1, j = 1, n;
    ll x, y;
  	cin >> n;
    x = number(i, 3);
    y = number(j, 5);
    while (i <= n && j <= n)
        if (x <= y) {
	      		cout << x << '\n';
            x = number(++i, 3);
        } else {
      			cout << y << '\n';
            y = number(++j, 5);
        }
    while (i <= n) {
		    cout << x << '\n';
        x = number(++i, 3);
    }
    while (j <= n) {
		    cout << y << '\n';
        y = number(++j, 5);
    }
    return 0;
}
