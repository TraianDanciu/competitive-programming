#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    vector<int> v;
    int val;
    while(cin >> val) {
        v.push_back(val);
    }
    for(int it = 0; it < 25; it++) {
        vector<int> w;
        for(int i = 0; i < (int)v.size(); i++) {
            if(v[i] == 0) {
                w.push_back(1);
            } else {
                int cifre = 0, copie = v[i];
                do {
                    cifre++;
                    copie /= 10;
                } while(copie > 0);
                if(cifre % 2 == 0) {
                    cifre /= 2;
                    int p10 = 1;
                    for(int i = 0; i < cifre; i++) {
                        p10 *= 10;
                    }
                    w.push_back(v[i] / p10);
                    w.push_back(v[i] % p10);
                } else {
                    w.push_back(v[i] * 2024);
                }
            }
        }
        v = w;
    }
    cout << (int)v.size() << "\n";
    return 0;
}
