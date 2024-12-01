#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    map<int, int> mpa, mpb;
    while(cin >> a >> b) {
        mpa[a]++;
        mpb[b]++;
    }
    long long answer = 0;
    for(auto it : mpa) {
        answer += 1LL * mpb[it.first] * it.second * it.first;
    }
    cout << answer << "\n";
    return 0;
}
