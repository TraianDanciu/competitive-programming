#include <bits/stdc++.h>

using namespace std;

int main() {
    int ch, cnt = 0;
    while(true) {
        ch = cin.get();
        if(ch == EOF) {
            break;
        }
        int n = ch - '0';
        while(isdigit(ch = cin.get())) {
            n = n * 10 + ch - '0';
        }
        int newn = 0, cresc = 1, desc = 1, ok = 1;
        while(ch != '\n') {
            while(isdigit(ch = cin.get())) {
                newn = newn * 10 + ch - '0';
            }
            
            if(newn > n) {
                desc = 0;
            } else if (newn < n) {
                cresc = 0;
            }
            if(abs(n - newn) < 1 || abs(n - newn) > 3) {
                ok = 0;
            }
            
            n = newn;
            newn = 0;
        }
        
        if(ok && (cresc || desc)) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}
