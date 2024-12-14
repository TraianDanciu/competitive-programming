#include <bits/stdc++.h>

using namespace std;

const int NLIN = 103;
const int NCOL = 101;
const int NROBOTS = 500;
const int BULAN = 100;

int cnt[NLIN][NCOL + 1];

struct Robot {
    int x, y, dx, dy;
} robots[NROBOTS];

int readInt(string s, int &i) {
    while(!isdigit(s[i]) && s[i] != '-') {
        i++;
    }
    int nr = 0, semn = 1;
    if(s[i] == '-') {
        semn = -1;
        i++;
    }
    do {
        nr = nr * 10 + (s[i] - '0');
    } while(isdigit(s[++i]));
    return nr * semn;
}

int main() {
    string s;
    for(int j = 0; j < NROBOTS; j++) {
        getline(cin, s);
        int i = 0;
        robots[j].y = readInt(s, i);
        robots[j].x = readInt(s, i);
        robots[j].dy = readInt(s, i);
        robots[j].dx = readInt(s, i);
        cnt[robots[j].x][robots[j].y]++;
    }
    
    int answer = 0;
    while(true) {
        answer++;
        int bulan = 0;
        for(int i = 0; i < NROBOTS; i++) {
            cnt[robots[i].x][robots[i].y]--;
            
            robots[i].x += robots[i].dx;
            if(robots[i].x >= NLIN) {
                robots[i].x -= NLIN;
            }
            if(robots[i].x < 0) {
                robots[i].x += NLIN;
            }
            
            robots[i].y += robots[i].dy;
            if(robots[i].y >= NCOL) {
                robots[i].y -= NCOL;
            }
            if(robots[i].y < 0) {
                robots[i].y += NCOL;
            }
            
            cnt[robots[i].x][robots[i].y]++;
            if(cnt[robots[i].x][robots[i].y + 1] > 0) {
                bulan++;
            }
        }
        
        if(bulan > BULAN) {
            break;
        }
    }
    
    cout << answer << "\n";
    return 0;
}
