#include <iostream>

using ll = long long;

const int vmax = 1000000, nmax = 1000000;
int fr[5 + vmax], a[5 + nmax], val[5 + nmax], bits[32];

void computeSieve() {
    for (int i = 1; i <= vmax; i++) {
        int cnt = 0;
        for (int j = i; j <= vmax; j += i) {
            cnt += fr[j];
        }
        if (cnt > 1) {
            for (int j = i; j <= vmax; j += i) {
                val[j] = i;
            }
        }
    }
}

void addValue(int x) {
    for (int i = 0; i < 32; i++) {
        if ((x >> i) & 1) {
            bits[i]++;
        }
    }
}

void removeValue(int x) {
    for (int i = 0; i < 32; i++) {
        if ((x >> i) & 1) {
            bits[i]--;
        }
    }
}

int sumOr() {
    int sol = 0;
    for (int i = 0; i < 32; i++) {
        if (bits[i]) {
            sol |= (1 << i);
        }
    }
    return sol;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, x;
    std::cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        fr[a[i]]++;
    }
    computeSieve();
    int right = 0;
    ll ans = 0;
    a[0] = val[0] = 0;
    for (int left = 1; left <= n; left++) {
        removeValue(val[a[left - 1]]);
        while (right < n && sumOr() < x) {
            right++;
            addValue(val[a[right]]);
        }
        if (sumOr() >= x) {
            ans += n - right + 1;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
