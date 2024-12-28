#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("biluta.in");
    ofstream fout("biluta.out");
    int x, n;
    fin >> x >> n;
    long long o = (long long)n * (n + 1) / 2;
    if (o <= x) {
        fout << o << '\n';
    } else {
        o -= x;
        o %= (long long)4 * x;
        if (o <= 2 * x) {
            fout << x - o << '\n';
        } else {
            fout << o - (long long)3 * x << '\n';
        }
    }
    return 0;
}
