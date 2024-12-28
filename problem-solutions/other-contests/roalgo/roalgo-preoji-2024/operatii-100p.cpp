#include <fstream>

using namespace std;

int main() {
    ifstream fin("operatii.in");
    ofstream fout("operatii.out");
    int t;
    fin >> t;
    while (t--) {
        long long a, b, k;
        fin >> a >> b >> k;
        k--;
        while (k > 0) {
            if (a > b) {
                if (a / b < k) {
                    k -= a / b;
                    a %= b;
                } else {
                    a -= b * k;
                    k = 0;
                }
            } else {
                if (b / a < k) {
                    k -= b / a;
                    b %= a;
                } else {
                    b -= a * k;
                    k = 0;
                }
            }
        }
        fout << a << ' ' << b << '\n';
    }
    return 0;
}
