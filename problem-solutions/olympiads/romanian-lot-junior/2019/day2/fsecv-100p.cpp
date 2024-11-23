#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e5;
int a[5 + nmax];

struct Query {
	int l, r, k, idx;
} q[5 + nmax];
int ans[5 + nmax];

const int bucket = 317;

inline bool cmp(Query a, Query b) {
	if (a.l / bucket == b.l / bucket)
		return a.r < b.r;
	return a.l / bucket < b.l / bucket;
} 

const int vmax = 1e5;
int fr[5 + 2 * vmax], frfr[5 + 2 * vmax];
#define fr (fr + vmax)
#define frfr (frfr + vmax)

inline void adauga(int pos) {
	frfr[fr[a[pos]]]--;
	fr[a[pos]]++;
	frfr[fr[a[pos]]]++;
}

inline void sterge(int pos) {
	frfr[fr[a[pos]]]--;
	fr[a[pos]]--;
	frfr[fr[a[pos]]]++;
}

int main() {
	ifstream cin("fsecv.in");
	ofstream cout("fsecv.out");
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r >> q[i].k;
		q[i].idx = i;
	}
	sort(q + 1, q + m + 1, cmp);
	for (int i = -vmax; i <= vmax; i++)
		frfr[fr[i]]++;
	int st = 1, dr = 1;
	adauga(1);
	for (int i = 1; i <= m; i++) {
		while (st < q[i].l)
			sterge(st++);
		while (st > q[i].l)
			adauga(--st);
		while (dr < q[i].r)
			adauga(++dr);
		while (dr > q[i].r)
			sterge(dr--);
		ans[q[i].idx] = frfr[q[i].k];
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
	return 0;
}
