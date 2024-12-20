#include <bits/stdc++.h>

using namespace std;

const int MAXN = 142, dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};

vector<string> mat;
int lsrc, csrc, ldest, cdest, n, m;
queue<pair<int, int>> q;
int dist[MAXN][MAXN];

int getDist() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }
    dist[lsrc][csrc] = 0;
    q.push({lsrc, csrc});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int l = it.first, c = it.second;
        for(int dir = 0; dir < 4; dir++) {
            int ll = l + dlin[dir], cc = c + dcol[dir];
            if(0 <= ll && ll < n && 0 <= cc && cc < m && dist[ll][cc] == -1 && mat[ll][cc] != '#') {
                dist[ll][cc] = 1 + dist[l][c];
                q.push({ll, cc});
            }
        }
    }
    return dist[ldest][cdest];
}

int main() {
    string s;
    while(cin >> s) {
        mat.push_back(s);
    }
    n = mat.size();
    m = mat[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'S') {
                lsrc = i;
                csrc = j;
            } else if(mat[i][j] == 'E') {
                ldest = i;
                cdest = j;
            }
        }
    }
    
    int true_dist = getDist(), answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '#') {
                mat[i][j] = '.';
                if(true_dist - getDist() >= 100) {
                    answer++;
                }
                mat[i][j] = '#';
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
