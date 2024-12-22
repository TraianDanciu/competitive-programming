#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e7, mod = 3e6 + 17;
int fact[5 + mod], invfact[5 + mod];

int lgp(int b, int n) {
	int r = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) r = 1LL * r * b % mod;
		b = 1LL * b * b % mod;
	}
	return r;
}

int comb(int n, int k) {
	if (n < k) return 0;
	if (n >= mod) return 1LL * comb(n / mod, k / mod) * comb(n % mod, k % mod) % mod;
	return 1LL * fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

int dp[5 + nmax], k;

int calc(int n) {
	if (dp[n] >= 0) return dp[n];
	dp[n] = comb(n + k - 1, k);
	for (int d = 2; d <= n; ++d) {
		int s = n / (n / d);
		dp[n] -= 1LL * (s - d + 1) * calc(n / d) % mod;
		if (dp[n] < 0) dp[n] += mod;
		d = s;
	}
	return dp[n];
}

int main() {
	ifstream cin("tupleco.in");
	ofstream cout("tupleco.out");
	int n;
	cin >> k >> n;
	fact[0] = 1;
	for (int i = 1; i < mod; ++i) fact[i] = 1LL * fact[i - 1] * i % mod;
	invfact[mod - 1] = lgp(fact[mod - 1], mod - 2);
	for (int i = mod - 2; i >= 0; --i) invfact[i] = 1LL * invfact[i + 1] * (i + 1) % mod;
	for (int i = 1; i <= n; ++i) dp[i] = -1;
	dp[1] = 1;
	cout << calc(n) << '\n';
	return 0;
}
