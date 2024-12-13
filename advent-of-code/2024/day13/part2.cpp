#include <bits/stdc++.h>

using namespace std;

int main() {
    __int128 sum = 0;
    string s;
    while(getline(cin, s)) {
        __int128 ax = -1, ay = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i])) {
                __int128 nr = 0;
                do {
                    nr = nr * 10 + (s[i] - '0');
                } while(isdigit(s[++i]));
                i--;
                if(ax == -1) {
                    ax = nr;
                } else {
                    ay = nr;
                }
            }
        }
        
        getline(cin, s);
        __int128 bx = -1, by = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i])) {
                __int128 nr = 0;
                do {
                    nr = nr * 10 + (s[i] - '0');
                } while(isdigit(s[++i]));
                i--;
                if(bx == -1) {
                    bx = nr;
                } else {
                    by = nr;
                }
            }
        }
        
        getline(cin, s);
        __int128 cx = -1, cy = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i])) {
                __int128 nr = 0;
                do {
                    nr = nr * 10 + (s[i] - '0');
                } while(isdigit(s[++i]));
                i--;
                if(cx == -1) {
                    cx = nr;
                } else {
                    cy = nr;
                }
            }
        }
        
        getline(cin, s); // e un '\n'
        
        cx += 10000000000000LL;
        cy += 10000000000000LL;
        
        __int128 difab = ax * by - ay * bx;
        __int128 difcb = cx * by - cy * bx;
        __int128 difca = cy * ax - cx * ay;
        if(difab != 0) {
            __int128 x = difcb / difab;
            __int128 y = difca / difab;
            if(x >= 0 && y >= 0 && difcb % difab == 0 && difca % difab == 0) {
                sum += 3 * x + y;
            }
        }
    }
    cout << (long long)sum << "\n";
    return 0;
}
