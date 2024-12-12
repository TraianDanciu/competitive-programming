#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> mat, oldmat;

int dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, area, perimeter, val;

void dfs(int l, int c) {
    mat[l][c] = '#';
    area++;
    for(int dir = 0; dir < 4; dir++) {
        int ll = l + dlin[dir], cc = c + dcol[dir];
        if(0 <= ll && ll < n && 0 <= cc && cc < m) {
            if(mat[ll][cc] == '#') {
                if(oldmat[ll][cc] != val) {
                    perimeter++;
                }
            } else if(mat[ll][cc] == val) {
                dfs(ll, cc);
            } else {
                perimeter++;
            }
        } else {
            perimeter++;
        }
    }
}

int main() {
    string s;
    while(cin >> s) {
        mat.push_back(s);
    }
    n = mat.size();
    m = mat[0].size();
    oldmat = mat;
    long long answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] != '#') {
                area = perimeter = 0;
                val = mat[i][j];
                dfs(i, j);
                answer += 1LL * area * perimeter;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
