#include <bits/stdc++.h>

using namespace std;

const int MOD = 666'013;

struct Matrix {
    int val[4][4];
  
    void mult(Matrix oth, Matrix &aux) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                aux.val[i][j] = 0;
                for(int k = 0; k < 4; k++) {
                    aux.val[i][j] = (aux.val[i][j] + 1LL * val[i][k] * oth.val[k][j]) % MOD;
                }
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                val[i][j] = aux.val[i][j];
            }
        }
    }
} result, base, aux;

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
    
    int answer = 0;
    if(n == 1) {
        answer = 1;
    } else if(n == 2) {
        answer = 5;
    } else if(n == 3) {
        answer = 11;
    } else {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                base.val[i][j] = 0;
            }
        }
        for(int i = 0; i < 3; i++) {
            base.val[i + 1][i] = 1;
        }
        base.val[0][3] = MOD - 1;
        base.val[1][3] = 1;
        base.val[2][3] = 5;
        base.val[3][3] = 1;
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                result.val[i][j] = 0;
            }
        }
        result.val[0][0] = 1;
        result.val[1][1] = 1;
        result.val[2][2] = 1;
        result.val[3][3] = 1;
        
        n -= 3;
        while(n > 0) {
            if(n % 2) {
                result.mult(base, aux);
            }
            base.mult(base, aux);
            n /= 2;
        }
        
        int coef[] = {1, 1, 5, 11};
        for(int i = 0; i < 4; i++) {
            answer += result.val[i][3] * coef[i];
        }
        answer %= MOD;
        if(answer < 0) {
            answer += MOD;
        }
    }
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
