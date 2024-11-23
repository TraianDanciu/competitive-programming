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

const int nmax = 1e4;
int aib[5 + nmax], which[5 + nmax], m;
void update(int pos, int val, int elem) {
    for (; pos <= m; pos += pos & -pos) {
        if (val > aib[pos]) {
            aib[pos] = val;
            which[pos] = elem;
        }
    }
}
int query(int pos) {
    int ans = 0;
    for (; pos > 0; pos -= pos & -pos) {
        if (aib[pos] > aib[ans]) {
            ans = pos;
        }
    }
    return ans;
}

int main() {
    ifstream fin("pokemoni.in");
    ofstream fout("pokemoni.out");
    int n, p;
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
        int poz = query(pts[i].col);
        dp[i] = 1 + aib[poz];
        nxt[i] = which[poz];
        update(pts[i].col, dp[i], i);
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
    for (int i = 1; i <= m; i++) {
        aib[i] = which[i] = 0;
    }
    for (int i = 1; i <= p; i++) {
        dp[i] = 1 + aib[query(pts[i].col)];
        update(pts[i].col, dp[i], i);
        ans = max(ans, dp[i]);
    }
    fout << p - ans << "\n";
    return 0;
}
