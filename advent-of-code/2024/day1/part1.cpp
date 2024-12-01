#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, n = 0;
    vector<int> va, vb;
    while(cin >> a >> b) {
        va.push_back(a);
        vb.push_back(b);
        n++;
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    long long answer = 0;
    for(int i = 0; i < n; i++) {
        answer += abs(va[i] - vb[i]);
    }
    cout << answer << "\n";
    return 0;
}
