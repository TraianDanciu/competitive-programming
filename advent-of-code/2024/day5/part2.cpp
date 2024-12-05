#include <bits/stdc++.h>

using namespace std;

__int128 p2[100];
int vpos[100];
vector<int> g[100];

void dfs(int i, __int128 &mask) {
    mask |= p2[i];
    for(auto it : g[i]) {
        if(vpos[it] && !(mask & p2[it])) {
            dfs(it, mask);
        }
    }
}

int main() {
    p2[0] = 1;
    for(int i = 1; i < 100; i++) {
        p2[i] = p2[i - 1] << 1;
    }
    string s;
    cin >> s;
    vector<int> invg[100];
    while(isdigit(s[0])) {
        int a = 10 * (s[0] - '0') + s[1] - '0', b = 10 * (s[3] - '0') + s[4] - '0';
        g[a].push_back(b);
        invg[b].push_back(a);
        cin >> s;
    }
    long long ans = 0;
    while(cin >> s) {
        int poz = 1;
        vector<int> v;
        for(int i = 0; i < (int)s.size(); i += 3) {
            int nr = 10 * (s[i] - '0') + (s[i + 1] - '0');
            v.push_back(nr);
            vpos[nr] = poz;
            poz++;
        }
        int ok = 1;
        for(int i = 0; i < 100; i++) {
            if(vpos[i] != 0) {
                for(auto it : invg[i]) {
                    if(vpos[it] > vpos[i]) {
                        ok = 0;
                    }
                }
            }
        }
        if(ok == 0) {
            vector<pair<int, int>> w;
            for(int j = 0; j < 100; j++) {
                if(vpos[j] != 0) {
                    __int128 mask = 0;
                    dfs(j, mask);
                    int nrbits = __builtin_popcountll(mask >> 62);
                    nrbits += __builtin_popcountll(mask & ((1LL << 62) - 1));
                    w.push_back({nrbits, j});
                }
            }
            sort(w.begin(), w.end());
            ans += w[(w.size() - 1) / 2].second;
        }
        for(int i = 0; i < 100; i++) {
            vpos[i] = 0;
        }
    }
    cout << ans << "\n";
}
