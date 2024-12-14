#include <bits/stdc++.h>

using namespace std;

const int NLIN = 103;
const int NCOL = 101;

int cnt[NLIN][NCOL];

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
    while(getline(cin, s)) {
        int i = 0;
        int y = readInt(s, i);
        int x = readInt(s, i);
        int dy = readInt(s, i);
        int dx = readInt(s, i);
        
        x += dx * 100;
        x %= NLIN;
        if(x < 0) {
            x += NLIN;
        }
        
        y += dy * 100;
        y %= NCOL;
        if(y < 0) {
            y += NCOL;
        }
        
        cnt[x][y]++;
    }
    
    long long answer = 1;
    
    int sum = 0;
    for(int i = 0; i < NLIN / 2; i++) {
        for(int j = 0; j < NCOL / 2; j++) {
            sum += cnt[i][j];
        }
    }
    answer *= sum;
    
    sum = 0;
    for(int i = 0; i < NLIN / 2; i++) {
        for(int j = NCOL / 2 + 1; j < NCOL; j++) {
            sum += cnt[i][j];
        }
    }
    answer *= sum;
    
    sum = 0;
    for(int i = NLIN / 2 + 1; i < NLIN; i++) {
        for(int j = 0; j < NCOL / 2; j++) {
            sum += cnt[i][j];
        }
    }
    answer *= sum;
    
    sum = 0;
    for(int i = NLIN / 2 + 1; i < NLIN; i++) {
        for(int j = NCOL / 2 + 1; j < NCOL; j++) {
            sum += cnt[i][j];
        }
    }
    answer *= sum;
    
    cout << answer << "\n";
    return 0;
}
