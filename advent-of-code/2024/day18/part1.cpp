#include <bits/stdc++.h>

using namespace std;

const int n = 70, dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};
int dist[n + 1][n + 1];
queue<pair<int, int>> q;

int main() {
    string s;
    int cnt = 0;
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
        dist[l][c] = -1;
        
        cnt++;
        if(cnt == 1024) {
            break;
        }
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
    cout << dist[n][n] - 1 << "\n";
    return 0;
}
