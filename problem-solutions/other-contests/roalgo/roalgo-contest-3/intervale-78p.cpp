#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5e5;
int frequency[NMAX+5][30];

class Query {
    private:
        int left, right;
        
        void read() {
            cin>>left>>right;
        }
        
        void solve() {
            int cnt_odd = 0;
            for (int i = 0; i < 26; i++)
                if ((frequency[right][i]-frequency[left-1][i])%2)
                    cnt_odd++;
            if (cnt_odd <= 1)
                cout<<"DA\n";
            else
                cout<<"NU\n";
        }
    
    public:
        Query() {
            read(), solve();
        }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    string s;
    int t;
    cin>>t>>s;
    int n = s.size();
    s = "#"+s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++)
            frequency[i][j] = frequency[i-1][j];
        frequency[i][s[i]-'a']++;
    }
    while (t--)
        Query query;
    return 0;
}
