#include <bits/stdc++.h>

using namespace std;

const int n = 70, dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};
int dist[n + 1][n + 1];
queue<pair<int, int>> q;

int main() {
    string s;
    vector<pair<int, int>> points;
    while(cin >> s) {
        int l = 0, i = 0, c = 0;
        while(isdigit(s[i])) {
            l = l * 10 + s[i] - '0';
            i++;
        }
        i++;
        while(i < (int)s.size()) {
            c = c * 10 + s[i] - '0';
            i++;
        }
        points.push_back({l, c});
    }
    
    int st = 0, dr = points.size();
    while(dr - st > 1) {
        int mij = (st + dr) / 2;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dist[i][j] = 0;
            }
        }
        for(int i = 0; i <= mij; i++) {
            dist[points[i].first][points[i].second] = -1;
        }
        
        dist[0][0] = 1;
        q.push({0, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int l = it.first, c = it.second;
            for(int dir = 0; dir < 4; dir++) {
                int ll = l + dlin[dir], cc = c + dcol[dir];
                if(0 <= ll && ll <= n && 0 <= cc && cc <= n && dist[ll][cc] == 0) {
                    dist[ll][cc] = dist[l][c] + 1;
                    q.push({ll, cc});
                }
            }
        }
        
        if(dist[n][n] == 0) {
            dr = mij;
        } else {
            st = mij;
        }
    }
    
    cout << points[dr].first << "," << points[dr].second << "\n";
    return 0;
}
