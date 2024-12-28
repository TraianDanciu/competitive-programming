#include <bits/stdc++.h>

#define int long long

using namespace std;

class Query {
    private:
        int k;
        
        void read() {
            cin>>k;
        }
        
        bool verify(const int &number) {
            long double expression = (number*number*number*number-3*number*number*number-
                                   2*number*number+5)/1000.0+10;
            return expression <= k;
        }
        
        void solve() {
            int left = 4, right = 1e4, ans;
            while (left <= right) {
                int middle = (left+right)/2;
                if (verify(middle))
                    ans = middle, left = middle+1;
                else
                    right = middle-1;
            }
            cout<<ans-4+1<<'\n';
        }
    
    public:
        Query() {
            read(), solve();
        }
};

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int t = 1;
    cin>>t;
    while (t--)
        Query query;
    return 0;
}
