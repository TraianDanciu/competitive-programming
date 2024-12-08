#include <bits/stdc++.h>

using namespace std;

string digits[] = {"one", "two", "three", "four", "five", "six", "seven",
                    "eight", "nine"};

int main() {
    string s;
    int answer = 0;
    while(cin >> s) {
        int f = -1, l = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i])) {
                if(f == -1) {
                    f = s[i] - '0';
                }
                l = s[i] - '0';
            } else {
                for(int j = 0; j < 9; j++) {
                    int ok = 1;
                    for(int p = 0; p < (int)digits[j].size(); p++) {
                        if(i + p >= (int)s.size() || s[i + p] != digits[j][p]) {
                            ok = 0;
                        }
                    }
                    if(ok) {
                        if(f == -1) {
                            f = j + 1;
                        }
                        l = j + 1;
                    }
                }
            }
        }
        answer += f * 10 + l;
    }
    cout << answer << "\n";
    return 0;
}
