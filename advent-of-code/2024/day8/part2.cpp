#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<string> mat;
    while(cin >> s) {
        mat.push_back(s);
    }
    int n = mat.size(), m = mat[0].size();
    map<char, vector<pair<int, int>>> poz;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] != '.') {
                poz[mat[i][j]].push_back({i, j});
            }
        }
    }
    int cnt = 0;
    for(auto &it : poz) {
        for(int i = 0; i < (int)it.second.size(); i++) {
            for(int j = i + 1; j < (int)it.second.size(); j++) {
                int ldif = it.second[i].first - it.second[j].first;
                int cdif = it.second[i].second - it.second[j].second;
                
                int l = it.second[i].first, c = it.second[i].second;
                while(0 <= l && l < n && 0 <= c && c < m) {
                    if(mat[l][c] != '#') {
                        mat[l][c] = '#';
                        cnt++;
                    }
                    l += ldif;
                    c += cdif;
                }
                
                l = it.second[j].first; c = it.second[j].second;
                while(0 <= l && l < n && 0 <= c && c < m) {
                    if(mat[l][c] != '#') {
                        mat[l][c] = '#';
                        cnt++;
                    }
                    l -= ldif;
                    c -= cdif;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
