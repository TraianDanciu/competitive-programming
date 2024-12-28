#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  
  if(n > m) {
    swap(n, m);
    swap(a, b);
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  vector<int> atrash;
  int aptr = 0, bptr = 0;
  while(aptr < n && bptr < m) {
    if(a[aptr] < b[bptr]) {
      atrash.push_back(a[aptr++]);
    } else if(a[aptr] > b[bptr]) {
      bptr++;
    } else {
      aptr++;
      bptr++;
    }
  }
  while(aptr < n) {
    atrash.push_back(a[aptr++]);
  }
  
  cout << atrash.size() + m - n << "\n";
  return 0;
}
