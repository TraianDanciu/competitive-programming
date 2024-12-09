#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> v;

int main() {
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) {
        if(i % 2) {
            for(int j = '0'; j < s[i]; j++) {
                v.push_back(-1);
            }
        } else {
            for(int j = '0'; j < s[i]; j++) {
                v.push_back(i / 2);
            }
        }
    }
    int st = 0, dr = v.size() - 1;
    while(st < dr) {
        while(st < (int)v.size() && v[st] != -1) {
            st++;
        }
        while(dr >= 0 && v[dr] == -1) {
            dr--;
        }
        if(st < dr) {
            v[st++] = v[dr];
            v[dr--] = -1;
        }
    }
    long long answer = 0;
    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i] == -1) {
            break;
        }
        answer += v[i] * i;
    }
    cout << answer << "\n";
    return 0;
}
