#include <bits/stdc++.h>

using namespace std;

int viz[26 * 26][26 * 26];
int counted[26 * 26][26 * 26][26 * 26];

int main() {
    string s;
    while(cin >> s) {
        int s1 = (s[0] - 'a') * 26 + (s[1] - 'a');
        int s2 = (s[3] - 'a') * 26 + (s[4] - 'a');
        viz[s1][s2] = viz[s2][s1] = 1;
    }
    
    for(int i = 0; i < 26; i++) {
        int s1 = ('t' - 'a') * 26 + i;
        for(int j = 0; j < 26 * 26; j++) {
            for(int k = 0; k < 26 * 26; k++) {
                if(viz[s1][j] && viz[j][k] && viz[k][s1]) {
                    counted[s1][j][k] = 1;
                    counted[s1][k][j] = 0;
                    counted[j][s1][k] = 0;
                    counted[j][k][s1] = 0;
                    counted[k][j][s1] = 0;
                    counted[k][s1][j] = 0;
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < 26 * 26; i++) {
        for(int j = 0; j < 26 * 26; j++) {
            for(int k = 0; k < 26 * 26; k++) {
                answer += counted[i][j][k];
            }
        }
    }
    cout << answer << "\n";
}
