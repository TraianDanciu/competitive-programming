#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int, int> fr, newfr;

signed main() {
    int val;
    while(cin >> val) {
        fr[val]++;
    }
    for(int i = 0; i < 75; i++) {
        newfr.clear();
        for(auto it : fr) {
            if(it.first == 0) {
                newfr[1] += it.second;
            } else {
                int cifre = 0, copie = it.first;
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
                    newfr[it.first / p10] += it.second;
                    newfr[it.first % p10] += it.second;
                } else {
                    newfr[it.first * 2024] += it.second;
                }
            }
        }
        fr = newfr;
    }
    int sum = 0;
    for(auto it : fr) {
        sum += it.second;
    }
    cout << sum << "\n";
    return 0;
}
