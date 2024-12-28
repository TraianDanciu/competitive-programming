#include <bits/stdc++.h>
#warning sunt pe onlinegdb

using namespace std;

const int nmax = 600;
int v1[5 + nmax][5 + nmax], v2[5 + nmax][5 + nmax], smen[5 + nmax][5 + nmax];
long long v3[5 + nmax][5 + nmax], mat[5 + nmax][5 + nmax], sum[5 + nmax][5 + nmax];

inline long long query(int l1, int c1, int l2, int c2) {
    if (l1 > l2 || c1 > c2) {
        return 0;
    }
    return sum[l2][c2] - sum[l1 - 1][c2] - sum[l2][c1 - 1] + sum[l1 - 1][c1 - 1];
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return mat[a.first][a.second] * smen[a.first][a.second] > mat[b.first][b.second] * smen[b.first][b.second];
}

int main() {
    #ifdef ONLINE_JUDGE
        ifstream cin("partsum.in");
        ofstream cout("partsum.out");
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v1[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v2[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v3[i][j];
        }
    }
    // calculez matricea mat
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int l = i - v1[i][j], c = j - v2[i][j];
            mat[i][j] = v3[i][j] - query(l, c, i, j - 1) - query(l, c, i - 1, j) + query(l, c, i - 1, j - 1);
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    // calculez in cate sume apare mat[i][j]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            smen[i - v1[i][j]][j - v2[i][j]]++;
            smen[i - v1[i][j]][j + 1]--;
            smen[i + 1][j - v2[i][j]]--;
            smen[i + 1][j + 1]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            smen[i][j] += smen[i - 1][j] + smen[i][j - 1] - smen[i - 1][j - 1];
        }
    }
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v.emplace_back(i, j);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < k; i++) {
        cout << v[i].first << ' ' << v[i].second << " 0\n";
        mat[v[i].first][v[i].second] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += query(i - v1[i][j], j - v2[i][j], i, j);
        }
    }
    cout << ans << '\n';
    return 0;
}
