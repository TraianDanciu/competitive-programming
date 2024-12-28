// eliminare gaussiana :money_mouth:
// pastrez doar puterile de 2

#include <bits/stdc++.h>
using namespace std;
int main() {
	int p2 = 1, e = 0, n, x;
	cin >> n >> x;
	while(p2 <= n) {
		p2 *= 2;
		e++;
	}
	// am e puteri si pot sa formez de la 0 la p2-1
	if(x < p2) {
		e = n - e; // elimin cele e puteri
		int ans = 1, b = 2;
		while(e > 0) {
			if(e & 1) {
				ans = 1LL * ans * b % 1000000007;
			}
			b = 1LL * b * b % 1000000007;
			e >>= 1;
		}
		cout << ans << "\n";
	} else {
		cout << "0\n";	
	}
	return 0;
}
