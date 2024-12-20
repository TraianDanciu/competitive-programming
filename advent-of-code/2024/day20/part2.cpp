#include <bits/stdc++.h>

using namespace std;

const int MAXN = 142, dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};

vector<string> mat;
int lsrc, csrc, ldest, cdest, n, m;
queue<pair<int, int>> q;
int dist1[MAXN][MAXN], dist2[MAXN][MAXN];

void getDist1() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist1[i][j] = -1;
        }
    }
    dist1[lsrc][csrc] = 0;
    q.push({lsrc, csrc});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int l = it.first, c = it.second;
        for(int dir = 0; dir < 4; dir++) {
            int ll = l + dlin[dir], cc = c + dcol[dir];
            if(0 <= ll && ll < n && 0 <= cc && cc < m && dist1[ll][cc] == -1 && mat[ll][cc] != '#') {
                dist1[ll][cc] = 1 + dist1[l][c];
                q.push({ll, cc});
            }
        }
    }
}

void getDist2() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist2[i][j] = -1;
        }
    }
    dist2[ldest][cdest] = 0;
    q.push({ldest, cdest});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int l = it.first, c = it.second;
        for(int dir = 0; dir < 4; dir++) {
            int ll = l + dlin[dir], cc = c + dcol[dir];
            if(0 <= ll && ll < n && 0 <= cc && cc < m && dist2[ll][cc] == -1 && mat[ll][cc] != '#') {
                dist2[ll][cc] = 1 + dist2[l][c];
                q.push({ll, cc});
            }
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
    
    getDist1();
    getDist2();
    int answer = 0, target = dist1[ldest][cdest] - 100;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] != '#') {
                for(int deltai = -20; deltai <= 20; deltai++) {
                    for(int deltaj = -20; deltaj <= 20; deltaj++) {
                        if(abs(deltai) + abs(deltaj) <= 20) {
                            int ii = i + deltai, jj = j + deltaj;
                            if(0 <= ii && ii < n && 0 <= jj && jj < m && mat[ii][jj] != '#') {
                                if(dist1[i][j] + dist2[ii][jj] + abs(deltai) + abs(deltaj) <= target) {
                                    answer++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
