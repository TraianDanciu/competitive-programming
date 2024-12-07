#include <bits/stdc++.h>

using namespace std;

const int NUM_LINES = 850;

long long target;
vector<long long> v;
int found;

void bkt(int step, long long total) {
    if(step == (int)v.size()) {
        if(total == target) {
            found = 1;
        }
    } else {
        if(total + v[step] <= target) {
            bkt(step + 1, total + v[step]);
        }
        if(target / total >= v[step]) {
            bkt(step + 1, total * v[step]);
        }
        long long p10 = 1;
        while(p10 <= v[step]) {
            p10 *= 10;
        }
        if(target / total >= p10 && total * p10 + v[step] <= target) {
            bkt(step + 1, total * p10 + v[step]);
        }
    }
}

int main() {
    long long answer = 0;
    for(int t = 0; t < NUM_LINES; t++) {
        // Fiecare numar va avea un spatiu dupa el in afara de ultimul
        char last_ch = ' ';
        scanf("%lld: ", &target);
        v.clear();
        while(!feof(stdin) && last_ch == ' ') {
            long long nr;
            scanf("%lld%c", &nr, &last_ch);
            v.push_back(nr);
        }
        
        found = 0;
        bkt(1, v[0]);
        if(found) {
            answer += target;
        }
    }
    cout << answer << "\n";
    return 0;
}
