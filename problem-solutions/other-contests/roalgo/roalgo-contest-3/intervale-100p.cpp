#include <bits/stdc++.h>

#pragma GCC optimize("O2", "unroll-loops")

using namespace std;

const int NMAX = 5e6;
int odd[NMAX+5];

class Query {
    private:
        int left, right;
        
        void read() {
            cin>>left>>right;
            left--, right--;
        }
        
        void solve() {
            bool ok = false;
            for (short i = 0; i < 26; i++)
                if (left == 0)
                    if (odd[right] & (1 << i))
						if (ok) {
							cout<<"NU\n";
							return;
						}
						else
							ok = true;
                    else;
                else
					if ((odd[right] & (1 << i)) != (odd[left-1] & (1 << i)))
						if (ok) {
							cout<<"NU\n";
							return;
						}
						else
							ok = true;
            cout<<"DA\n";
        }
    
    public:
        Query() {
            read(), solve();
        }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    char c;
    int t, i = 0;
    cin>>t;
	cin.get();
	cin.get(c);
    while (c >= 'a' && c <= 'z') {
        if (i)
            odd[i] = odd[i-1];
        odd[i] ^= (1 << (c-'a'));
        i++;
		cin.get(c);
    }
    while (t--)
        Query query;
    return 0;
}
