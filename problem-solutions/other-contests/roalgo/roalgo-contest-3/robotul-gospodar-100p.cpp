#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int NMAX = 3e5;
int c[NMAX+5], right_max[NMAX+5], left_max[NMAX+5], added[NMAX+5], needed[NMAX+5];

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n, k, x, t;
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>c[i];
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && c[i] <= c[st.top()])
            st.pop();
        if (st.empty())
            left_max[i] = 1;
        else
            left_max[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && c[i] >= c[st.top()])
            st.pop();
        if (st.empty())
            right_max[i] = n;
        else
            right_max[i] = st.top();
        st.push(i);
    }
    cin>>k;
    while (k--)
        cin>>x>>t, added[left_max[x]] += t, added[right_max[x]+1] -= t;
    for (int i = 1; i <= n; i++)
        added[i] += added[i-1];
    int left_over = 0;
    for (int i = 1; i <= n; i++)
        if (added[i] >= c[i])
            needed[i] = 0, left_over += added[i]-c[i];
        else
            needed[i] = c[i]-added[i];
    sort(needed+1, needed+n+1);
    int it = 1, ans = 0;
    while (it <= n && left_over >= needed[it] && left_over) {
        if (needed[it] > 0)
            ans++;
        left_over -= needed[it];
        it++;
    }
    cout<<ans<<'\n';
    return 0;
}
