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
    long long answer = 0, n;
    while(cin >> n) {
        for(int i = 0; i < 2000; i++) {
            n = newNumber(n);
        }
        answer += n;
    }
    cout << answer << "\n";
}
