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
    int l0 = 0, c0 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '^') {
                l0 = i;
                c0 = j;
            }
        }
    }
    int cnt = 0;
    auto w = v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(w[i][j] == '.') {
                v[i][j] = '#';
                set<pair<pair<int, int>, char>> st;
                int ok = 0, l = l0, c = c0;
                while(!st.count({{l, c}, v[l][c]})) {
                    st.insert({{l, c}, v[l][c]});
                    if(v[l][c] == '^') {
                        v[l][c] = '.';
                        while(l > 0 && v[l - 1][c] == '.') {
                            l--;
                        }
                        if(l == 0) {
                            break;
                        }
                        v[l][c] = '>';
                    } else if(v[l][c] == '>') {
                        v[l][c] = '.';
                        while(c < m - 1 && v[l][c + 1] == '.') {
                            c++;
                        }
                        if(c == m - 1) {
                            break;
                        }
                        v[l][c] = 'v';
                    } else if(v[l][c] == 'v') {
                        v[l][c] = '.';
                        while(l < n - 1 && v[l + 1][c] == '.') {
                            l++;
                        }
                        if(l == n - 1) {
                            break;
                        }
                        v[l][c] = '<';
                    } else {
                        v[l][c] = '.';
                        while(c > 0 && v[l][c - 1] == '.') {
                            c--;
                        }
                        if(c == 0) {
                            break;
                        }
                        v[l][c] = '^';
                    }
                }
                if(st.count({{l, c}, v[l][c]})) {
                    cnt++;
                }
                v = w;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
