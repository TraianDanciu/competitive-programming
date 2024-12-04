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
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            if(mat[i][j] == 'A') {
                int ok = 1;
                if(mat[i - 1][j - 1] == 'M' && mat[i + 1][j + 1] == 'S') {
                    
                } else if(mat[i - 1][j - 1] == 'S' && mat[i + 1][j + 1] == 'M') {
                    
                } else {
                    ok = 0;
                }
                if(mat[i + 1][j - 1] == 'M' && mat[i - 1][j + 1] == 'S') {
                    
                } else if(mat[i + 1][j - 1] == 'S' && mat[i - 1][j + 1] == 'M') {
                    
                } else {
                    ok = 0;
                }
                cnt += ok;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
