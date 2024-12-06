#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
vector<string> v;

int iese(int l, int c) {
    return l < 0 || c < 0 || l >= n || c >= m;
}

int main() {
    while(cin >> s) {
        v.push_back(s);
    }
    n = v.size();
    m = v[0].size();
    int l = 0, c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '^') {
                l = i;
                c = j;
            }
        }
    }
    vector<vector<int>> viz(n, vector<int>(m));
    while(true) {
        viz[l][c] = 1;
        if(v[l][c] == '^') {
            v[l][c] = '.';
            while(!iese(l - 1, c) && v[l - 1][c] == '.') {
                viz[--l][c] = 1;
            }
            if(iese(l - 1, c)) {
                break;
            }
            v[l][c] = '>';
        } else if(v[l][c] == '>') {
            v[l][c] = '.';
            while(!iese(l, c + 1) && v[l][c + 1] == '.') {
                viz[l][++c] = 1;
            }
            if(iese(l, c + 1)) {
                break;
            }
            v[l][c] = 'v';
        } else if(v[l][c] == 'v') {
            v[l][c] = '.';
            while(!iese(l + 1, c) && v[l + 1][c] == '.') {
                viz[++l][c] = 1;
            }
            if(iese(l + 1, c)) {
                break;
            }
            v[l][c] = '<';
        } else {
            v[l][c] = '.';
            while(!iese(l, c - 1) && v[l][c - 1] == '.') {
                viz[l][--c] = 1;
            }
            if(iese(l, c - 1)) {
                break;
            }
            v[l][c] = '^';
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cnt += viz[i][j];
        }
    }
    cout << cnt << "\n";
    return 0;
}
