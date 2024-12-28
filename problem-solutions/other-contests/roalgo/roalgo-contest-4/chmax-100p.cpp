#include <bits/stdc++.h>

/// lol era cu stiva

using namespace std;

int n;
vector<int> a, max_left, max_right;

class Query {
    private:
        int left, right, position;
        
        void reset() {
            
        }
        
        void read() {
            cin >> left >> right >> position;
        }
        
        void solve() {
            cout << (max_left[position] < left && right < max_right[position]);
        }
    
    public:
        Query() {
            reset(), read(), solve();
        }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    stack<int> st;
    int t = 1;
    cin >> n >> t;
    a.resize(n + 1);
    max_left.resize(n + 1); /// lol am uitat de astea
    max_right.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        if (st.empty())
            max_left[i] = 0;
        else
            max_left[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        if (st.empty())
            max_right[i] = n + 1;
        else
            max_right[i] = st.top();
        st.push(i);
    }
    while (t--)
        Query query;
    return 0;
}
