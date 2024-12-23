#include <bits/stdc++.h>

using namespace std;

int viz[26 * 26][26 * 26];
vector<int> clique, answer;

void bkt(int node) {
    if(node == 26 * 26) {
        if(answer.size() < clique.size()) {
            answer = clique;
        }
    } else {
        int ok = 1;
        for(int i : clique) {
            if(!viz[i][node]) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            clique.push_back(node);
            bkt(node + 1);
            clique.pop_back();
        }
        bkt(node + 1);
    }
}

int main() {
    string s;
    while(cin >> s) {
        int s1 = (s[0] - 'a') * 26 + (s[1] - 'a');
        int s2 = (s[3] - 'a') * 26 + (s[4] - 'a');
        viz[s1][s2] = viz[s2][s1] = 1;
    }

    bkt(0);

    for(int i = 1; i < answer.size(); i++) {
        cout << (char)('a' + answer[i - 1] / 26) << (char)('a' + answer[i - 1] % 26) << ",";
    }
    cout << (char)('a' + answer.back() / 26) << (char)('a' + answer.back() % 26) << "\n";
    return 0;
}
