#include <bits/stdc++.h>

using namespace std;

int check(vector<int> v) {
    int cresc = 1, desc = 1, ok = 1;
    for(int i = 1; i < (int)v.size(); i++) {
        if(v[i - 1] > v[i]) {
            cresc = 0;
        }
        if(v[i - 1] < v[i]) {
            desc = 0;
        }
        if(abs(v[i] - v[i - 1]) < 1 || abs(v[i] - v[i - 1]) > 3) {
            ok = 0;
        }
    }
    return ok && (cresc || desc);
}

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
        vector<int> v{n};
        while(ch != '\n') {
            n = 0;
            while(isdigit(ch = cin.get())) {
                n = n * 10 + ch - '0';
            }
            v.push_back(n);
        }
        
        int ok = check(v);
        for(int i = 0; i < (int)v.size(); i++) {
            vector<int> w;
            for(int j = 0; j < (int)v.size(); j++) {
                if(j != i) {
                    w.push_back(v[j]);
                }
            }
            if(check(w)) {
                ok = 1;
            }
        }
        cnt += ok;
    }
    cout << cnt << "\n";
}
