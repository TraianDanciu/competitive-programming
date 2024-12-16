#include <bits/stdc++.h>

using namespace std;

int dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};

int main() {
    string s;
    vector<string> mat;
    while(cin >> s) {
        mat.push_back(s);
    }
    int n = mat.size(), m = mat[0].size();
    
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4)));
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'S') {
                x = i;
                y = j;
            }
            for(int k = 0; k < 4; k++) {
                dist[i][j][k] = 1e9;
            }
        }
    }
    
    priority_queue<pair<int, pair<pair<int, int>, int>>> pq;
    dist[x][y][1] = 0;
    pq.push({0, {{x, y}, 1}});
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int d = -it.first;
        int l = it.second.first.first;
        int c = it.second.first.second;
        int dir = it.second.second;
        
        if(dist[l][c][dir] != d) {
            continue;
        }
        
        int newl = l + dlin[dir];
        int newc = c + dcol[dir];
        if(mat[newl][newc] != '#' && dist[newl][newc][dir] > d + 1) {
            dist[newl][newc][dir] = d + 1;
            pq.push({-(d + 1), {{newl, newc}, dir}});
        }
        
        dir = (dir + 1) % 4;
        newl = l + dlin[dir];
        newc = c + dcol[dir];
        if(mat[newl][newc] != '#' && dist[newl][newc][dir] > d + 1001) {
            dist[newl][newc][dir] = d + 1001;
            pq.push({-(d + 1001), {{newl, newc}, dir}});
        }
        
        dir = (dir + 2) % 4;
        newl = l + dlin[dir];
        newc = c + dcol[dir];
        if(mat[newl][newc] != '#' && dist[newl][newc][dir] > d + 1001) {
            dist[newl][newc][dir] = d + 1001;
            pq.push({-(d + 1001), {{newl, newc}, dir}});
        }
    }
    
    int answer = 1e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'E') {
                for(int k = 0; k < 4; k++) {
                    answer = min(answer, dist[i][j][k]);
                }
            }
        }
    }
    cout << answer << "\n";
    
    return 0;
}
