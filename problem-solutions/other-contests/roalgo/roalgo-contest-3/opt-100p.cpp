#include <bits/stdc++.h>

#define int long long

using namespace std;

const int NMAX = 1e5;
pair<int, int> points[NMAX+5], benefits[NMAX+5];
int b[NMAX+5];

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n, k;
	cin >> n >> k;
    for (int i = 1; i <= n; i++)
		cin >> points[i].first >> points[i].second;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            benefits[i].first += (points[i].first - points[i - 1].first);
        if (i < n)
            benefits[i].first += (points[i + 1].first - points[i].first);
        benefits[i].second = i;
    }
    sort(benefits + 1, benefits + n + 1, [&](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    });
    int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
		if (cnt + b[benefits[i].second] <= k)
			cnt += b[benefits[i].second], ans += benefits[i].first * b[benefits[i].second];
		else {
			ans += (k - cnt) * benefits[i].first;
			cnt = k;
			break;
		}
    for (int i = 1; i < n; i++)
        ans += (points[i].second + points[i + 1].second) * (points[i + 1].first - points[i].first);
    cout << ans / 2 << '.' << ans % 2 * 5;
    return 0;
}
