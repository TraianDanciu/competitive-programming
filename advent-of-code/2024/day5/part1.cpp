#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> g[100];
    while(isdigit(s[0])) {
        int a = 10 * (s[0] - '0') + s[1] - '0', b = 10 * (s[3] - '0') + s[4] - '0';
        g[b].push_back(a);
        cin >> s;
    }
    long long ans = 0;
    while(cin >> s) {
        int fpos[100] = {}, lpos[100] = {}, poz = 1;
        vector<int> v;
        for(int i = 0; i < (int)s.size(); i += 3) {
            int nr = 10 * (s[i] - '0') + (s[i + 1] - '0');
            v.push_back(nr);
            if(fpos[nr] == 0) {
                fpos[nr] = poz;
            }
            lpos[nr] = poz;
            poz++;
        }
        int ok = 1;
        for(int i = 0; i < 100; i++) {
            if(lpos[i] != 0) {
                for(auto it : g[i]) {
                    if(fpos[it] > lpos[i]) {
                        ok = 0;
                    }
                }
            }
        }
        if(ok) {
            ans += v[(v.size() - 1) / 2];
        }
    }
    cout << ans << "\n";
}
