#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int answer = 0, ptr = 0;
    while(getline(cin, s)) {
        map<string, int> mp;
        ptr++;
        int i = 0;
        s.push_back(';');
        while(s[i] != ':') {
            i++;
        }
        i++;
        while(i < (int)s.size()) {
            while(!isdigit(s[i])) {
                i++;
            }
            int nr = 0;
            do {
                nr = nr * 10 + s[i] - '0';
            } while(isdigit(s[++i]));
            
            while(!isalpha(s[i])) {
                i++;
            }
            string t = "";
            do {
                t.push_back(s[i]);
            } while(isalpha(s[++i]));
            
            mp[t] = max(mp[t], nr);
            i++;
        }
        
        answer += mp["red"] * mp["green"] * mp["blue"];
    }
    cout << answer << "\n";
    return 0;
}
