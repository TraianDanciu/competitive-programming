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
                
                int nl = it.second[i].first + ldif, nc = it.second[i].second + cdif;
                if(0 <= nl && nl < n && 0 <= nc && nc < m) {
                    if(mat[nl][nc] != '#') {
                        mat[nl][nc] = '#';
                        cnt++;
                    }
                }
                
                nl = it.second[j].first - ldif; nc = it.second[j].second - cdif;
                if(0 <= nl && nl < n && 0 <= nc && nc < m) {
                    if(mat[nl][nc] != '#') {
                        mat[nl][nc] = '#';
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
