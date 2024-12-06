#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string xmas = "XMAS";

int main() {
    vector<string> mat;
    string s;
    while(cin >> s) {
        mat.push_back(s);
    }
    int n = mat.size(), m = mat[0].size(), cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int dir = 0; dir < 8; dir++) {
                int ok = 1;
                for(int k = 0; k < 4; k++) {
                    int ii = i + k * dx[dir], jj = j + k * dy[dir];
                    if(0 <= ii && ii < n && 0 <= jj && jj < m && mat[ii][jj] == xmas[k]) {
                        
                    } else {
                        ok = 0;
                    }
                }
                cnt += ok;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
