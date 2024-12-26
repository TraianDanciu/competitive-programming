#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> mp;
    string s;
    while(true) {
        cin >> s;
        if(s.back() != ':') {
            break;
        }
        s.pop_back();
        int val;
        cin >> val;
        mp[s] = val;
    }
    
    set<vector<string>> ops;
    
    while(true) {
        string op, t, aux, unde;
        cin >> op >> t >> aux >> unde;
        ops.insert({s, op, t, unde});
        if(!(cin >> s)) {
            break;
        }
    }
    
    while(!ops.empty()) {
        for(auto it : ops) {
            if(mp.count(it[0]) && mp.count(it[2])) {
                if(it[1] == "AND") {
                    mp[it[3]] = mp[it[0]] & mp[it[2]];
                } else if(it[1] == "OR") {
                    mp[it[3]] = mp[it[0]] | mp[it[2]];
                } else {
                    mp[it[3]] = mp[it[0]] ^ mp[it[2]];
                }
                ops.erase(it);
                break;
            }
        }
    }
    
    __int128 answer = 0;
    for(char a = '0'; a <= '9'; a++) {
        for(char b = '0'; b <= '9'; b++) {
            string z = "z";
            z.push_back(a);
            z.push_back(b);
            int number = (a - '0') * 10 + (b - '0');
            answer |= (__int128)mp[z] << number;
        }
    }
    
    cout << (long long)answer << "\n";
    return 0;
}
