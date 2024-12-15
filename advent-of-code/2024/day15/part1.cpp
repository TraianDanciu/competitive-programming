#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<string> mat;
    while(cin >> s) {
        if(s[0] != '#') {
            break;
        }
        mat.push_back(s);
    }
    int n = mat.size(), m = mat[0].size();
    
    string t;
    while(cin >> t) {
        s += t;
    }
    
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '@') {
                x = i;
                y = j;
            }
        }
    }
    
    for(char move : s) {
        if(move == '^') {
            int i = x - 1;
            while(mat[i][y] == 'O') {
                i--;
            }
            if(mat[i][y] != '#') {
                for(; i < x; i++) {
                    mat[i][y] = mat[i + 1][y];
                }
                mat[x][y] = '.';
                x--;
            }
        } else if(move == '>') {
            int j = y + 1;
            while(mat[x][j] == 'O') {
                j++;
            }
            if(mat[x][j] != '#') {
                for(; j > y; j--) {
                    mat[x][j] = mat[x][j - 1];
                }
                mat[x][y] = '.';
                y++;
            }
        } else if(move == 'v') {
            int i = x + 1;
            while(mat[i][y] == 'O') {
                i++;
            }
            if(mat[i][y] != '#') {
                for(; i > x; i--) {
                    mat[i][y] = mat[i - 1][y];
                }
                mat[x][y] = '.';
                x++;
            }
        } else {
            int j = y - 1;
            while(mat[x][j] == 'O') {
                j--;
            }
            if(mat[x][j] != '#') {
                for(; j < y; j++) {
                    mat[x][j] = mat[x][j + 1];
                }
                mat[x][y] = '.';
                y--;
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'O') {
                answer += 100 * i + j;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
