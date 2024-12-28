#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

const int nmax = 200000;
int a[5 + nmax], st[5 + nmax], dr[5 + nmax], aib[5 + nmax];

void update(int poz) {
  for(; poz <= nmax; poz += poz & -poz) {
    aib[poz]++;
  }
}

int query(int poz) {
  int ans = 0;
  for(; poz > 0; poz &= poz - 1) {
    ans += aib[poz];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  long long k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  long long total = 0;
  for(int i = 1; i <= n; i++) {
    st[i] = i - 1 - query(a[i]);
    total += st[i];
    update(a[i]);
  }
  for(int i = 1; i <= nmax; i++) {
    aib[i] = 0;
  }
  for(int i = n; i >= 1; i--) {
    dr[i] = query(a[i] - 1);
    update(a[i]);
  }
  
  long long ans = (total == k);
  map<long long, __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less_equal<int>,
          __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>> mp;
  for(int i = n; i > 0; i--) {
    long long target = total - st[i] - dr[i] - k;
    ans += target == 0;
    
    // presupunem ca vrem sa eliminam i si j, cu i < j
    // avem doua cazuri: a[i] <= a[j] si a[i] > a[j]
    if(mp.count(target)) {
      ans += mp[target].size() - mp[target].order_of_key(a[i]);
    }
    
    target++;
    if(mp.count(target)) {
      ans += mp[target].order_of_key(a[i]);
    }
    
    mp[st[i] + dr[i]].insert(a[i]);
  }
  
  cout << ans << "\n";
  return 0;
}
