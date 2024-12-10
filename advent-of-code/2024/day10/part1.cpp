#include <bits/stdc++.h>

using namespace std;

int dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};

int main() {
    string s;
    vector<string> mat;
    while(cin >> s) {
        mat.push_back(s);
    }
    int n = mat.size(), m = mat[0].size(), score = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '0') {
                queue<pair<int, int>> q;
                q.push({i, j});
                vector<vector<int>> viz(n, vector<int>(m));
                while(!q.empty()) {
                    pair<int, int> poz = q.front();
                    q.pop();
                    int l = poz.first, c = poz.second;
                    if(viz[l][c]) {
                        continue;
                    }
                    viz[l][c] = 1;
                    if(mat[l][c] == '9') {
                        score++;
                    } else {
                        for(int dir = 0; dir < 4; dir++) {
                            int ll = l + dlin[dir], cc = c + dcol[dir];
                            if(0 <= ll && ll < n && 0 <= cc && cc < m && mat[ll][cc] == mat[l][c] + 1) {
                                q.push({ll, cc});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << score << "\n";
    return 0;
}
