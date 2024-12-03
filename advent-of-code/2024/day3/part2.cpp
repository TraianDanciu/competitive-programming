#include <bits/stdc++.h>

using namespace std;

int main() {
    long long answer = 0;
    int ch, ok = 1;
    while((ch = cin.get()) != EOF) {
        if(ch == 'm') {
            ch = cin.get();
            if(ch == 'u') {
                ch = cin.get();
                if(ch = 'l') {
                    ch = cin.get();
                    if(ch == '(') {
                        int nr = 0;
                        while(isdigit(ch = cin.get())) {
                            nr = nr * 10 + ch - '0';
                        }
                        if(ch == ',') {
                            int nr2 = 0;
                            while(isdigit(ch = cin.get())) {
                                nr2 = nr2 * 10 + ch - '0';
                            }
                            if(ch == ')' && ok) {
                                answer += 1LL * nr * nr2;
                            }
                        }
                    }
                }
            }
        } else if(ch == 'd') {
            ch = cin.get();
            if(ch == 'o') {
                ch = cin.get();
                if(ch == '(') {
                    ch = cin.get();
                    if(ch == ')') {
                        ok = 1;
                    }
                } else if(ch == 'n') {
                    ch = cin.get();
                    if(ch == '\'') {
                        ch = cin.get();
                        if(ch == 't') {
                            ch = cin.get();
                            if(ch == '(') {
                                ch = cin.get();
                                if(ch == ')') {
                                    ok = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
