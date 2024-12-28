#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cdcq.in");
ofstream fout("cdcq.out");

const int NMAX = 3e5;

int freq0[NMAX+5], freqmod9[NMAX+5][9];

int lgpow(int base, int exponent) {
    int ans = 1;
    while (exponent) {
        if (exponent%2)
            ans = 1ll*ans*base%9;
        base = 1ll*base*base%9;
        exponent /= 2;
    }
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    fin.tie(nullptr), fout.tie(nullptr);

    int n, q, x, start, finish;
    fin>>n;
    for (int i = 1; i <= n; i++) {
        fin>>x, freq0[i] = freq0[i-1]+(x == 0);
        for (int j = 0; j < 9; j++)
            freqmod9[i][j] = freqmod9[i-1][j]+(x%9 == j);
    }
    fin>>q;
    while (q--) {
        fin>>start>>finish;
        if (freq0[finish]-freq0[start-1])
            fout<<"0\n";
        else {
            int ans = 1;
            for (int j = 0; j < 9; j++)
                ans = 1ll*ans*lgpow(j, freqmod9[finish][j]-freqmod9[start-1][j])%9;
            if (ans == 0)
                ans = 9;
            fout<<ans<<'\n';
        }
    }
    return 0;
}
