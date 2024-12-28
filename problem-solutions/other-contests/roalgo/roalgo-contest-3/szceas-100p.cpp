#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5;

class Query {
    private:
        int n, a[NMAX+5];
        
        void read() {
            cin>>n;
            for (int i = 1; i <= n; i++)
                cin>>a[i];
        }
        
        void solve() {
            if (n <= 2) {
                cout<<"DA\n";
                return;
            }
            int first_pos = 1;
            while (first_pos < n && a[first_pos] < a[first_pos+1])
                first_pos++;
            if (first_pos == n) {
                cout<<"NU\n";
                return;
            }
            int last_pos = n;
            while (last_pos > 1 && a[last_pos-1] < a[last_pos])
                last_pos--;
            if (last_pos == 1) {
                cout<<"NU\n";
                return;
            }
            if (last_pos == first_pos) {
                cout<<"NU\n";
                return;
            }
            swap(a[last_pos], a[first_pos]);
            for (int i = 1; i < n; i++)
                if (a[i] >= a[i+1]) {
                    cout<<"NU\n";
                    return;
                }
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

    int t = 1;
    cin>>t;
    while (t--)
        Query query;
    return 0;
}
