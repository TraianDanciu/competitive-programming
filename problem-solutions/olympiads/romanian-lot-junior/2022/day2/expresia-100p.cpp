#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("expresia.in");
ofstream fout("expresia.out");

const int NMAX = 500, PMAX = 18;
char operators[NMAX+5];
int digits[NMAX+5];
long long dp[NMAX+5][PMAX+5][PMAX+5];

int nrstars(const int &left, const int &right)
{
    int cnt = 0;

    for (int i = left; i <= right; i++)
        if (operators[i] == '*') cnt++;

    return cnt;
}

long long calculation(const int &left, const int &right)
{
    long long result = 1;

    for (int i = left; i <= right; i++) result *= digits[i];

    return result;
}

int main()
{
    int n, q, p = 0;
    long long solution = 0;
    fin>>n>>q>>digits[1];
    n = n/2+1;

    for (int i = 2; i <= n; i++) {
        fin>>operators[i]>>digits[i];

        if (operators[i] == '*') p++;
    }

    dp[1][0][0] = digits[1];

    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= q && j <= p; j++)
            for (int k = 0; k <= p && k < i; k++) {
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]+digits[i]);

                for (int x = 0; x <= k && x < i; x++) {
                    int difference = x-nrstars(i-x+1, i), nrchanges = j-difference;

                    if (nrchanges < 0) break;

                    dp[i][j][k] = max(dp[i][j][k], dp[i-x-1][nrchanges][k-x]+calculation(i-x, i));
                }
            }

    for (short j = 0; j <= q && j <= p; j++) solution = max(solution, dp[n][j][p]);

    fout<<solution;
    return 0;
}
