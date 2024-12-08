#include <bits/stdc++.h>

using namespace std;

vector<string> mat;
int n, m;

int isok(int l, int c) {
    if(l < 0 || c < 0 || l >= n || c >= m) {
        return 0;
    }
    if(isdigit(mat[l][c]) || mat[l][c] == '.') {
        return 0;
    }
    return 1;
}

int main() {
    string s;
    while(cin >> s) {
        mat.push_back(s);
    }
    n = mat.size();
    m = mat[0].size();
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    vector<vector<int>> prod(n, vector<int>(m, 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(isdigit(mat[i][j])) {
                int nr = 0, p = j;
                while(p < m && isdigit(mat[i][p])) {
                    nr = nr * 10 + mat[i][p] - '0';
                    mat[i][p++] = '.';
                }
                for(int k = j - 1; k <= p; k++) {
                    if(isok(i - 1, k)) {
                        cnt[i - 1][k]++;
                        prod[i - 1][k] *= nr;
                    }
                    if(isok(i, k)) {
                        cnt[i][k]++;
                        prod[i][k] *= nr;
                    }
                    if(isok(i + 1, k)) {
                        cnt[i + 1][k]++;
                        prod[i + 1][k] *= nr;
                    }
                }
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cnt[i][j] == 2) {
                answer += prod[i][j];
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
