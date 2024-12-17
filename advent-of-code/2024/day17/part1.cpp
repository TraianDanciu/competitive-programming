#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c;
    string s;
    cin >> s >> s >> a >> s >> s >> b >> s >> s >> c >> s >> s;
    
    string t = s;
    s = "";
    for(int i = 0; i < (int)t.size(); i++) {
        if(t[i] != ',') {
            s.push_back(t[i]);
        }
    }
    
    int ptr = 0;
    while(ptr < (int)s.size()) {
        int x = s[ptr] - '0';
        int y = s[ptr + 1] - '0';
        int ycombo = y;
        if(y == 4) {
            ycombo = a;
        } else if(y == 5) {
            ycombo = b;
        } else if(y == 6) {
            ycombo = c;
        }
        
        if(x == 0) {
            a >>= ycombo;
        } else if(x == 1) {
            b ^= y;
        } else if(x == 2) {
            b = ycombo % 8;
        } else if(x == 3) {
            if(a != 0) {
                ptr = y;
                continue;
            }
        } else if(x == 4) {
            b ^= c;
        } else if(x == 5) {
            cout << ycombo % 8 << ",";
        } else if(x == 6) {
            b = a >> ycombo;
        } else {
            c = a >> ycombo;
        }
        ptr += 2;
    }
    
    return 0;
}
