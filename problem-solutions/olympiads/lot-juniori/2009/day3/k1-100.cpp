#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("k1.in");
    ofstream cout("k1.out");
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        pq.push(val);
    }
    long long ans = 0;
    while (pq.size() >= 2)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << '\n';
    return 0;
}