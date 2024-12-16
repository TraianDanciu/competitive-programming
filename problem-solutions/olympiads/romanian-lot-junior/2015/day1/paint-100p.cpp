#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back

using namespace std;

const int NMAX = 25e4;
int diff[NMAX + 5];

signed main() {
	#ifndef TEST 
		freopen("paint.in", "r", stdin);
		freopen("paint.out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k, m, ans = 0;
	cin >> n >> k >> m;
	while (m--) {
		int start, length;
		cin >> start >> length;
		diff[start]++;
		diff[start + length]--;
	}
	for (int i = 1; i <= n; i++)
		diff[i] += diff[i - 1];
	for (int i = 0; i < n; i++)
		if (diff[i] < k)
			ans++;
	cout << ans;
	return 0;
}
