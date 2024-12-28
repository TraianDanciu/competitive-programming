/// Chertes Andrei
// 16:00 - 19:00
#include <bits/stdc++.h>

using namespace std;
using ll = long long; // sigma rule #1: don't use #define int long long

#ifdef LOCAL
ifstream fin("input");
ofstream fout("output");
#else
#define fin cin
#define fout cout
#endif

const int kMod = 998244353;
const int kS = 31596;

void multSelf(int &a, int b) {
	a = (long long) a * b % kMod;
}

int mult(int a, int b) {
	multSelf(a, b);
	return a;
}

int p1[kS + 1];
int p2[kS + 1];

int main() {
	fin.tie(nullptr)->sync_with_stdio(false);
	int tc;
	fin >> tc;
	p1[0] = 1;
	for(int i = 1; i <= kS; i++) {
		p1[i] = mult(p1[i - 1], 2);
	}
	p2[0] = 1;
	for(int i = 1; i <= kS; i++) {
		p2[i] = mult(p2[i - 1], p1[kS]);
	}
	while(tc--) {
		ll n;
		fin >> n;
		int desired = (n - 1 + kMod - 1) % (kMod - 1), my_pow = mult(p2[desired / kS], p1[desired % kS]);
		fout << mult(n % kMod, mult(3, my_pow)) << '\n';
	}
	return 0;
}
