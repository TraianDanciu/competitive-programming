#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    map<string, long long> mp;
    string answer = "";
    long long maxfreq = -1;
    for(int j = 1; j <= tt; j++) {
        string s;
        cin >> s;
        string t = "";
        int i = 0;
        while(s[i] != ':') {
            t.push_back(s[i++]);
        }
        
        int nr = 0;
        i++;
        while(s[i] != ':') {
            nr = nr * 10 + s[i++] - '0';
        }
        int ceas = nr * 60;
        i++;
        nr = 0;
        while(i < (int)s.size()) {
            nr = nr * 10 + s[i++] - '0';
        }
        ceas += nr;
        ceas /= 15;
        if(j == tt) {
            ceas *= 2;
        }
        mp[t] += ceas;
        if(mp[t] > maxfreq) {
            answer = t;
            maxfreq = mp[t];
        }
    }
    cout << answer << " " << maxfreq << " " << mp["ASG"] << "\n";
    return 0;
}
