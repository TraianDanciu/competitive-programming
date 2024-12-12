#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> mat, oldmat;

int dlin[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, val;
set<pair<int, int>> region;
set<pair<pair<int, int>, int>> perimeter;

void dfs(int l, int c) {
    mat[l][c] = '#';
    region.insert({l, c});
    for(int dir = 0; dir < 4; dir++) {
        int ll = l + dlin[dir], cc = c + dcol[dir];
        if(0 <= ll && ll < n && 0 <= cc && cc < m && mat[ll][cc] == val) {
            dfs(ll, cc);
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
                val = mat[i][j];
                dfs(i, j);
                
                for(auto it : region) {
                    int l = it.first, c = it.second;
                    for(int dir = 0; dir < 4; dir++) {
                        int ll = l + dlin[dir], cc = c + dcol[dir];
                        if(!region.count({ll, cc})) {
                            perimeter.insert({{ll, cc}, dir});
                        }
                    }
                }
                
                int nrsides = 0;
                while(!perimeter.empty()) {
                    auto it = *perimeter.begin();
                    perimeter.erase(perimeter.begin());
                    int l = it.first.first, c = it.first.second, dir = it.second;
                    nrsides++;
                    
                    int dl, dc;
                    if(dir % 2 == 0) {
                        dl = 0;
                        dc = 1;
                    } else {
                        dl = 1;
                        dc = 0;
                    }
                    
                    int newl = l + dl, newc = c + dc;
                    while(perimeter.count({{newl, newc}, dir})) {
                        perimeter.erase({{newl, newc}, dir});
                        newl += dl;
                        newc += dc;
                    }
                    
                    newl = l - dl;
                    newc = c - dc;
                    while(perimeter.count({{newl, newc}, dir})) {
                        perimeter.erase({{newl, newc}, dir});
                        newl -= dl;
                        newc -= dc;
                    }
                }
                
                answer += 1LL * nrsides * (int)region.size();
                region.clear();
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
