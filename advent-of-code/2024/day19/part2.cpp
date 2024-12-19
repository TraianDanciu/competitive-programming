#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main() {
    string s;
    while(true) {
        cin >> s;
        int to_break = 0;
        if(s.back() == ',') {
            s.pop_back();
        } else {
            to_break = 1;
        }
        
        mp[s] = 1;
        
        if(to_break) {
            break;
        }
    }
    
    long long answer = 0;
    while(cin >> s) {
        s = "#" + s;
        vector<long long> dp((int)s.size(), 0);
        dp[0] = 1;
        for(int i = 0; i < (int)s.size(); i++) {
            string t = "";
            for(int j = i + 1; j < (int)s.size(); j++) {
                t.push_back(s[j]);
                if(mp[t]) {
                    dp[j] += dp[i];
                }
            }
        }
        answer += dp[(int)s.size() - 1];
    }
    cout << answer << "\n";
    return 0;
}
