#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<pair<int, int>> v;
    for(int i = 0; i < (int)s.size(); i++) {
        if(i % 2) {
            v.push_back({s[i] - '0', -1});
        } else {
            v.push_back({s[i] - '0', i / 2});
        }
    }
    
    vector<vector<pair<int, int>>> w(s.size());
    for(int i = (int)v.size() - 1; i >= 0; i--) {
        if(i % 2 == 0) {
            int ok = i;
            for(int j = 0; j < i; j++) {
                if(j % 2 && v[j].first >= v[i].first) {
                    v[j].first -= v[i].first;
                    ok = j;
                    break;
                }
            }
            w[ok].push_back({i, v[i].first});
            if(ok == i) {
                v[i].first = 0;
            }
        }
    }
    
    int ptr = 0;
    long long answer = 0;
    for(int i = 0; i < (int)v.size(); i++) {
        for(auto it : w[i]) {
            for(int j = 0; j < it.second; j++) {
                answer += v[it.first].second * (ptr++);
            }
        }
        ptr += v[i].first;
    }
    cout << answer << "\n";
    return 0;
}
