#include <bits/stdc++.h>

using namespace std;

const int MOD = 666'013;

int lgput(int a, int n) {
    int r = 1;
    while(n > 0) {
        if(n % 2) {
            r = 1LL * r * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n /= 2;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    int k;
    cin >> n >> k;
    
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    for(int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + 5 * dp[i - 2] + dp[i - 3] - dp[i - 4]) % MOD;
        if(dp[i] < 0) {
            dp[i] += MOD;
        }
    }
    int answer = dp[n];
    if(answer < k) {
        cout << "0\n";
    } else {
        int prod1 = 1, prod2 = 1;
        for(int i = 1; i <= answer; i++) {
            prod1 = 1LL * prod1 * i % MOD;
        }
        for(int i = 1; i <= k; i++) {
            prod2 = 1LL * prod2 * i % MOD;
        }
        for(int i = 1; i <= answer - k; i++) {
            prod2 = 1LL * prod2 * i % MOD;
        }
        cout << 1LL * prod1 * lgput(prod2, MOD - 2) % MOD << "\n";
    }
    return 0;
}
