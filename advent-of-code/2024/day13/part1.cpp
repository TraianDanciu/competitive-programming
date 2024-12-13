#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;
    string s;
    while(getline(cin, s)) {
        int ax = -1, ay = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i])) {
                int nr = 0;
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
        int bx = -1, by = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i])) {
                int nr = 0;
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
        int cx = -1, cy = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i])) {
                int nr = 0;
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
        
        int answer = 1000;
        for(int i = 0; i <= 100; i++) {
            if(i * ax <= cx && i * ay <= cy) {
                int newcx = cx - i * ax, newcy = cy - i * ay;
                if(newcx % bx == 0 && newcy % by == 0 && newcx / bx == newcy / by) {
                    answer = min(answer, 3 * i + newcx / bx);
                }
            }
        }
        sum += answer == 1000 ? 0 : answer;
    }
    cout << sum << "\n";
    return 0;
}
