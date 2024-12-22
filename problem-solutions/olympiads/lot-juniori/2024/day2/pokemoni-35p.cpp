#include <bits/stdc++.h>

using namespace std;

const int pmax = 1e5;
struct Coord {
    int lin, col;
} pts[5 + pmax];
bool cmp(Coord a, Coord b) {
    if (a.lin == b.lin) {
        return a.col < b.col;
    }
    return a.lin < b.lin;
}

int dp[5 + pmax], nxt[5 + pmax], taken[5 + pmax];

int main() {
    ifstream fin("pokemoni.in");
    ofstream fout("pokemoni.out");
    int n, m, p;
    fin >> n >> m >> p;
    n++;
    m++;
    for (int i = 1; i <= p; i++) {
        fin >> pts[i].lin >> pts[i].col;
        pts[i].lin++;
        pts[i].col++;
    }
    sort(pts + 1, pts + p + 1, cmp);
    int pozmax = 0;
    for (int i = 1; i <= p; i++) {
        dp[i] = 0;
        for (int j = i - 1; j > 0; j--) {
            if (dp[j] >= dp[i] && pts[j].col <= pts[i].col) {
                dp[i] = dp[j];
                nxt[i] = j;
            }
        }
        dp[i]++;
        if (dp[i] > dp[pozmax]) {
            pozmax = i;
        }
    }
    while (pozmax > 0) {
        taken[pozmax] = 1;
        pozmax = nxt[pozmax];
    }
    int ptr = 0;
    for (int i = 1; i <= p; i++) {
        if (!taken[i]) {
            pts[++ptr] = pts[i];
        }
    }
    p = ptr;
    int ans = 0;
    for (int i = 1; i <= p; i++) {
        dp[i] = 0;
        for (int j = i - 1; j > 0; j--) {
            if (pts[j].col <= pts[i].col) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        ans = max(ans, ++dp[i]);
    }
    fout << p - ans << "\n";
    return 0;
}
