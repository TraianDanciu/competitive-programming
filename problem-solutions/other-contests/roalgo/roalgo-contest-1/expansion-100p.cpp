#include <iostream>
#include <fstream>
#include <deque>
#include <cstring>

using namespace std;

ifstream fin("expansion.in");
ofstream fout("expansion.out");

const int NMAX = 2e3, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n, m, visited[NMAX+5][NMAX+5], number_r;
char a[NMAX+5][NMAX+5], b[NMAX+5][NMAX+5];

pair<int, int> mp(const int &First, const int &Second) {
    pair<int, int> Return;
    Return.first = First;
    Return.second = Second;
    return Return;
}

inline bool inmatrix(const int &line, const int &column) {
    return line >= 1 && line <= n && column >= 1 && column <= m;
}
bool verify(const int &length) {
    deque< pair<int, int> > dq;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            b[i][j] = a[i][j];
            if (a[i][j] == '#')
                dq.push_back(mp(i, j)), visited[i][j] = 1;
        }
    while (!dq.empty()) {
        pair<int, int> current = dq[0];
        dq.pop_front();
        if (visited[current.first][current.second] == length+1)
            break;
        for (int direction = 0; direction < 4; direction++) {
            int x = current.first+dx[direction], y = current.second+dy[direction];
            if (inmatrix(x, y))
                if (!visited[x][y])
                    dq.push_back(mp(x, y)), b[x][y] = '#', 
                    visited[x][y] = visited[current.first][current.second]+1;
        }
    }
    memset(visited, false, sizeof(visited));
    dq.clear();
    bool found = false;
    for (int i = 1; i <= n && !found; i++)
        for (int j = 1; j <= m && !found; j++)
            if (b[i][j] == 'R')
                dq.push_back(mp(i, j)), visited[i][j] = found = true;
    int found_r = 0;
    while (!dq.empty()) {
        pair<int, int> current = dq[0];
        dq.pop_front();
        found_r += (b[current.first][current.second] == 'R');
        for (int direction = 0; direction < 4; direction++) {
            int x = current.first+dx[direction], y = current.second+dy[direction];
            if (inmatrix(x, y))
                if (!visited[x][y] && b[x][y] != '#')
                    dq.push_back(mp(x, y)), visited[x][y] = true;
        }
    }
    return found_r == number_r;
}

int main() {
    ios_base :: sync_with_stdio(false);
    fin.tie(nullptr), fout.tie(nullptr);

    fin>>n>>m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin>>a[i][j], number_r += (a[i][j] == 'R');
    int left = 0, right = n+m, solution = 0;
    while (left <= right) {
        int middle = (left+right)/2;
        if (verify(middle))
            solution = middle, left = middle+1;
        else
            right = middle-1;
    }
    fout<<solution;
    return 0;
}
