#include <bits/stdc++.h>

using namespace std;

const int MAXK = 100;
int v[4][MAXK + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, insule, q;
    cin >> n >> m >> insule >> q;
    for(int i = 1; i <= insule; i++) {
        int l, c, x;
        string s;
        cin >> l >> c >> x >> s;
        int maxl = l, maxc = c, minl = l, minc = c;
        for(int i = 0; i < x; i++) {
            if(s[i] == 'N') {
                l--;
            } else if(s[i] == 'E') {
                c++;
            } else if(s[i] == 'S') {
                l++;
            } else {
                c--;
            }
            maxl = max(maxl, l);
            maxc = max(maxc, c);
            minl = min(minl, l);
            minc = min(minc, c);
        }
        v[0][i] = maxl;
        v[1][i] = maxc;
        v[2][i] = minl;
        v[3][i] = minc;
    }
    while(q--) {
        int l1, c1, l2, c2;
        cin >> l1 >> c1 >> l2 >> c2;
        int cnt = 0;
        for(int i = 1; i <= insule; i++) {
            if(l1 <= v[2][i] && v[0][i] <= l2 && c1 <= v[3][i] && v[1][i] <= c2) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
