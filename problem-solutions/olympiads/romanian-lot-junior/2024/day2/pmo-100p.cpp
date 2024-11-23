#include <fstream>
#include <string>
#include <algorithm>

std::ifstream fin("pmo.in");
std::ofstream fout("pmo.out");

std::istream &operator>>(std::istream &in, __int128 &n) {
    int i;
    std::string s;
    in >> s;
    n = 0;
    for (i = 0; i < (int)s.size(); i++) {
        n = n * 10 + s[i] - '0';
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, __int128 n) {
    std::string s = "";
    do {
        s.push_back('0' + n % 10);
        n /= 10;
    } while (n > 0);
    std::reverse(s.begin(), s.end());
    out << s;
    return out;
}

const int MAXP = 32'000;
const int MAXEXPS = 64;

char ciur[MAXP];
int prime[MAXP], exps[MAXEXPS], sumexp, nfact;
long long comb[MAXEXPS][MAXEXPS];
__int128 ways[MAXEXPS]; // ways[i] = nrmod de a scrie x ca prod de i nr

void precomputeSieve() {
    int i, j;
    for (i = 2; i * i < MAXP; i++) {
        if (ciur[i] == 0) {
            for (j = i * i; j < MAXP; j += i) {
                ciur[j] = 1;
            }
        }
    }
}

void precomputePrimes() {
    int i, p;
    p = 0;
    for (i = 2; i < MAXP; i++) {
        if (ciur[i] == 0) {
            prime[p++] = i;
        }
    }
}

void precomputeComb() {
    int i, j;
    comb[0][0] = 1;
    for (i = 1; i < MAXEXPS; i++) {
        comb[i][0] = 1;
        for (j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}

void precompute() {
    precomputeSieve();
    precomputePrimes();
    precomputeComb();
}

void decomposeInPrimes(int val) {
    int i;
    nfact = i = sumexp = 0;
    while (prime[i] * prime[i] <= val) {
        if (val % prime[i] == 0) {
            exps[nfact] = 0;
            do {
                exps[nfact]++;
                val /= prime[i];
            } while (val % prime[i] == 0);
            sumexp += exps[nfact++];
        }
        i++;
    }
    if (val > 1) {
        exps[nfact++] = 1;
        sumexp++;
    }
}

long long starsAndBars(int n, int k) {
    return comb[n + k - 1][k - 1];
}

void computeWays() {
    int i, j;
    for (i = 0; i <= sumexp; i++) {
        ways[i] = 1;
        for (j = 0; j < nfact; j++) {
            ways[i] *= starsAndBars(exps[j], i);
        }
    }
}

void calcAnswer() {
    int i, j;
    __int128 answer, prod;
    answer = 0;
    for (i = 1; i <= sumexp; i++) {
        for (j = 0; j < i; j++) {
            prod = comb[i][j] * ways[i - j];
            if (j % 2 == 0) {
                answer += prod;
            }
            else {
                answer -= prod;
            }
        }
    }
    fout << answer << "\n";
}

void answerQueries() {
    int t, x;
    fin >> t;
    while (t--) {
        fin >> x;
        decomposeInPrimes(x);
        computeWays();
        calcAnswer();
    }
}

int main() {
    precompute();
    answerQueries();
    return 0;
}
