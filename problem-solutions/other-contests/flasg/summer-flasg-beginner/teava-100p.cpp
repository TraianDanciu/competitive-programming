#include <iostream>

using namespace std;

#define MAXN 100000

long long sp[MAXN + 1];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> sp[i];
        sp[i] += sp[i - 1]; // sume partiale
    }
    
    int st, dr;
    cin >> st >> dr;
    long long ans = 0;
    for(; dr <= n; st++, dr++) { // luam fiecare secventa
        ans += sp[dr] - sp[st - 1]; // suma pe intervalul [st, dr]
    }
    
    cout << ans << "\n";
    return 0;
}
