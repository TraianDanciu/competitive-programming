#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back

/// 1 = \, 2 = _, 3 = /

using namespace std;

int n;
string s;
vector<int> sum1, sum2, sum3, first_pos1, first_pos2, first_pos3;

class Query {
    private:
		int query_left, query_right;
		
		void reset() {
			
		}
		
        void read() {
            cin >> query_left >> query_right;
        }
		
        void solve() {
            /// lol ce cautare binara nostima
            int left = 1, right = query_right - query_left + 1, ans = 0;
            while (left <= right) {
                int before1 = sum1[query_left - 1];
                int middle = (left + right) / 2;
                if (middle > n) {
                    right = middle - 1;
                    continue;
                }
                int position = first_pos1[before1 + middle];
                if (position == -1 || position > query_right) {
                    right = middle - 1;
                    continue;
                }
                int before2 = sum2[position];
                position = first_pos2[before2 + middle];
                if (position == -1 || position > query_right) {
                    right = middle - 1;
                    continue;
                }
                int before3 = sum3[position];
                position = first_pos3[before3 + middle];
                if (position == -1 || position > query_right) {
                    right = middle - 1;
                    continue;
                }
                left = middle + 1;
                ans = middle;
            }
            cout << ans << '\n';
        }
    
    public:
        Query() {
            reset(), read(), solve();
        }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	
    int t = 1;
    cin >> n >> t >> s;
    s = '#' + s;
    /// de ce tot uit de astea lol 
    sum1.resize(n + 1);
    sum2.resize(n + 1);
    sum3.resize(n + 1);
    first_pos1.resize(n + 1);
    first_pos2.resize(n + 1);
    first_pos3.resize(n + 1);
    for (int i = 1; i <= n; i++)
        first_pos1[i] = first_pos2[i] = first_pos3[i] = -1;
    for (int i = 1; i <= n; i++) {
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        sum3[i] = sum3[i - 1];
        switch (s[i]) {
            case '\\': {
                sum1[i]++;
                first_pos1[sum1[i]] = i;
                break;
            }
            
            case '_': {
                sum2[i]++;
                first_pos2[sum2[i]] = i;
                break;
            }
            
            case '/': {
                sum3[i]++;
                first_pos3[sum3[i]] = i;
                break;
            }
        }
    }
    while (t--)
		Query query;
    return 0;
}
