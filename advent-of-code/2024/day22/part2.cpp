#include <bits/stdc++.h>

using namespace std;

long long newNumber(long long n) {
    n ^= n << 6;
    n %= 16777216;
    n ^= n >> 5;
    n %= 16777216;
    n ^= n << 11;
    n %= 16777216;
    return n;
}

int main() {
    long long n;
    map<vector<long long>, long long> mp;
    while(cin >> n) {
        deque<long long> dq;
        set<vector<long long>> st;
        for(int i = 0; i < 2000; i++) {
            long long m = newNumber(n);
            dq.push_back(m % 10 - n % 10);
            n = m;
            if(i >= 3) {
                vector<long long> v = {dq[0], dq[1], dq[2], dq[3]};
                if(!st.count(v)) {
                    st.insert(v);
                    mp[v] += n % 10;
                }
                dq.pop_front();
            }
        }
    }
    long long answer = 0;
    for(auto it : mp) {
        answer = max(answer, it.second);
    }
    cout << answer << "\n";
}
