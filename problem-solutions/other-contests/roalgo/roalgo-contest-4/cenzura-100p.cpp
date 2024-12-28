#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, max_left, cnt_left, max_right, cnt_right;

class Query {
    private:
        int left, right;
        
        void reset() {
            
        }
        
        void read() {
            cin >> left >> right;
        }
        
        void solve() {
            if (left == 1 && right == n) {
                cout << "0 " << n << '\n';
                return;
            }
            if (left == 1) {
                cout << max_right[right + 1] << ' ' << cnt_right[right + 1] << '\n';
                return;
            }
            if (right == n) {
                cout << max_left[left - 1] << ' ' << cnt_left[left - 1] << '\n';
                return;
            }
            cout << max(max_left[left - 1], max_right[right + 1]) << ' ';
            if (max_left[left - 1] == max_right[right + 1])
                cout << cnt_left[left - 1] + cnt_right[right + 1] << '\n';
            if (max_left[left - 1] < max_right[right + 1])
                cout << cnt_right[right + 1] << '\n';
            if (max_left[left - 1] > max_right[right + 1])
                cout << cnt_left[left - 1] << '\n';
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
    cin >> n >> t;
    a.resize(n + 5);
    max_left.resize(n + 5);
    max_right.resize(n + 5);
    cnt_left.resize(n + 5);
    cnt_right.resize(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] > max_left[i - 1])
            max_left[i] = a[i], cnt_left[i] = 1;
        else if (a[i] == max_left[i - 1])
            cnt_left[i] = cnt_left[i - 1] + 1, max_left[i] = a[i];
        else
            max_left[i] = max_left[i - 1], cnt_left[i] = cnt_left[i - 1];
    for (int i = n; i >= 1; i--)
        if (a[i] > max_right[i + 1])
            max_right[i] = a[i], cnt_right[i] = 1;
        else if (a[i] == max_right[i + 1])
            cnt_right[i] = cnt_right[i + 1] + 1, max_right[i] = a[i];
        else
            max_right[i] = max_right[i + 1], cnt_right[i] = cnt_right[i + 1];
    while (t--)
        Query query;
    return 0;
}
