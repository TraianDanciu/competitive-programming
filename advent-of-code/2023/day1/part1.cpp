#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int answer = 0;
    while(cin >> s) {
        int f = -1, l = -1;
        for(char ch : s) {
            if(isdigit(ch)) {
                if(f == -1) {
                    f = ch - '0';
                }
                l = ch - '0';
            }
        }
        answer += f * 10 + l;
    }
    cout << answer << "\n";
    return 0;
}
