#include <bits/stdc++.h>

using namespace std;

bitset<1000005> obtainable;
int frequency[105];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n, nrtests, points;
    cin>>n;
    obtainable[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin>>nrtests;
        while (nrtests--)
            cin>>points, frequency[points]++;
    }
    for (int i = 1; i <= 100; i++) {
        int p2 = 1;
        while (frequency[i]) {
            frequency[i] -= p2;
            int total = i*p2;
            obtainable |= (obtainable << total);
            p2 *= 2;
            if (p2 > frequency[i])
                p2 = frequency[i];
        }
    }
    cout<<obtainable.count();
    return 0;
}
