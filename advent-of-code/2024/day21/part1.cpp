#include <bits/stdc++.h>

using namespace std;

const int NUM_TESTS = 5;
string s;

struct Stare {
    int i1, i2, i3, poz;
    
    bool operator <(Stare other) const {
        if(i1 == other.i1) {
            if(i2 == other.i2) {
                if(i3 == other.i3) {
                    return poz < other.poz;
                }
                return i3 < other.i2;
            }
            return i2 < other.i2;
        }
        return i1 < other.i1;
    }
};

int dp[11][5][5][5];
vector<Stare> g[11][5][5][5];
queue<Stare> q;

int sus[] = {2, 4, 5, 6, 7, 8, 9, -1, -1, -1, 3};
int stanga[] = {-1, -1, 1, 2, -1, 4, 5, -1, 7, 8, 0};
int jos[] = {-1, -1, 0, 10, 1, 2, 3, 4, 5, 6, -1};
int dreapta[] = {10, 2, 3, -1, 5, 6, -1, 8, 9, -1, -1};

int getval(int poz) {
    if(poz == 4) {
        return -1;
    }
    if(s[poz] == 'A') {
        return 10;
    }
    return s[poz] - '0';
}

int main() {
    for(int i1 = 0; i1 <= 10; i1++) {
        for(int poz = 0; poz < 4; poz++) {
            // Cazurile cand apasam A
            g[i1][2][0][poz].push_back({i1, 0, 0, poz});
            g[i1][3][0][poz].push_back({i1, 4, 0, poz});
            
            g[i1][2][1][poz].push_back({i1, 1, 1, poz});
            g[i1][3][1][poz].push_back({i1, 2, 1, poz});
            g[i1][4][1][poz].push_back({i1, 0, 1, poz});
            
            g[i1][0][2][poz].push_back({i1, 2, 2, poz});
            g[i1][4][2][poz].push_back({i1, 3, 2, poz});
            
            g[i1][0][3][poz].push_back({i1, 4, 3, poz});
            g[i1][1][3][poz].push_back({i1, 2, 3, poz});
            g[i1][2][3][poz].push_back({i1, 3, 3, poz});
            
            if(sus[i1] != -1) {
                g[i1][0][4][poz].push_back({sus[i1], 0, 4, poz});
            }
            if(stanga[i1] != -1) {
                g[i1][1][4][poz].push_back({stanga[i1], 1, 4, poz});
            }
            if(jos[i1] != -1) {
                g[i1][2][4][poz].push_back({jos[i1], 2, 4, poz});
            }
            if(dreapta[i1] != -1) {
                g[i1][3][4][poz].push_back({dreapta[i1], 3, 4, poz});
            }
            
            for(int i2 = 0; i2 <= 4; i2++) {
                // Cazurile cand apasam sus
                g[i1][i2][2][poz].push_back({i1, i2, 0, poz});
                g[i1][i2][3][poz].push_back({i1, i2, 4, poz});
                
                // Cazurile cand apasam stanga
                g[i1][i2][4][poz].push_back({i1, i2, 0, poz});
                g[i1][i2][3][poz].push_back({i1, i2, 2, poz});
                g[i1][i2][2][poz].push_back({i1, i2, 1, poz});
                
                // Cazurile cand apasam jos
                g[i1][i2][0][poz].push_back({i1, i2, 2, poz});
                g[i1][i2][4][poz].push_back({i1, i2, 3, poz});
                
                // Cazurile cand apasam dreapta
                g[i1][i2][0][poz].push_back({i1, i2, 4, poz});
                g[i1][i2][1][poz].push_back({i1, i2, 2, poz});
                g[i1][i2][2][poz].push_back({i1, i2, 3, poz});
            }
        }
    }
    
    long long answer = 0;
    for(int i = 0; i < NUM_TESTS; i++) {
        cin >> s;
        // dp[i1][i2][i3][poz] = numarul minim de apasari daca primul robot e la
        // cifra i1, al doilea robot e la cifra i2, al treilea robot e la cifra
        // i3, si am scris de la 0 la poz - 1
        
        for(int i1 = 0; i1 <= 10; i1++) {
            for(int i2 = 0; i2 <= 4; i2++) {
                for(int i3 = 0; i3 <= 4; i3++) {
                    for(int poz = 0; poz <= 4; poz++) {
                        dp[i1][i2][i3][poz] = 1e9;
                    }
                }
            }
        }
        dp[10][4][4][0] = 0;
        q.push({10, 4, 4, 0});
        while(!q.empty()) {
            auto nod = q.front();
            q.pop();
            int newdp = dp[nod.i1][nod.i2][nod.i3][nod.poz] + 1;
            
            if(nod.i1 == getval(nod.poz) && nod.i2 == 4 && nod.i3 == 4) {
                if(dp[nod.i1][nod.i2][nod.i3][nod.poz + 1] == 1e9) {
                    dp[nod.i1][nod.i2][nod.i3][nod.poz + 1] = newdp;
                    q.push({nod.i1, nod.i2, nod.i3, nod.poz + 1});
                }
            }
            
            for(auto vecin : g[nod.i1][nod.i2][nod.i3][nod.poz]) {
                if(dp[vecin.i1][vecin.i2][vecin.i3][vecin.poz] == 1e9) {
                    dp[vecin.i1][vecin.i2][vecin.i3][vecin.poz] = newdp;
                    q.push(vecin);
                }
            }
        }
        
        int answeri = 1e9;
        for(int i1 = 0; i1 <= 10; i1++) {
            for(int i2 = 0; i2 <= 4; i2++) {
                for(int i3 = 0; i3 <= 4; i3++) {
                    answeri = min(answeri, dp[i1][i2][i3][4]);
                }
            }
        }
        int nr = 0;
        for(int i = 0; i < 3; i++) {
            nr = nr * 10 + s[i] - '0';
        }
        answer += 1LL * answeri * nr;
    }
    cout << answer << "\n";
    return 0;
}
