// hai poate intra asa
#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5;
int a[5 + nmax], gasit;
set<int> poz[51];

void solve(int l, int r) {
  set<int>::iterator start = poz[1].lower_bound(l);
  if(start != poz[1].end() && (*start) <= r) {
    auto aux = start;
    aux++;
    if(aux != poz[1].end()) {
      auto aux2 = aux;
      aux2++;
      if(aux2 != poz[1].end() && *aux2 <= r) {
        cout << *aux << " " << *aux2 << " " << *start << "\n";
        gasit = 1;
        return;
      }
    }
    for(int i = 2; i <= 50; i++) {
      auto aux = poz[i].lower_bound(l);
      if(aux != poz[i].end()) {
        auto aux2 = aux;
        aux2++;
        if(aux2 != poz[i].end() && *aux2 <= r) {
          cout << *aux2 << " " << *aux << " " << *start << "\n";
          gasit = 1;
          return;
        }
      }
    }
  }
  
  for(int i = 2; i <= 7; i++) {
    auto aux = poz[i].lower_bound(l);
    if(aux != poz[i].end() && *aux <= r) {
      for(int j = i + i; j <= 50; j += i) {
        if(j / i == i) {
          auto aux2 = aux;
          aux2++;
          auto aux3 = poz[j].lower_bound(l);
          if(aux2 != poz[i].end() && *aux2 <= r && aux3 != poz[j].end() && *aux3 <= r) {
            cout << *aux3 << " " << *aux2 << " " << *aux << "\n";
            gasit = 1;
            return;
          }
        } else {
          auto aux3 = poz[j].lower_bound(l);
          auto aux2 = poz[j / i].lower_bound(l);
          if(aux3 != poz[j].end() && *aux3 <= r && aux2 != poz[j / i].end() && *aux2 <= r) {
            cout << *aux3 << " " << *aux2 << " " << *aux << "\n";
            gasit = 1;
            return;
          }
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    poz[a[i]].insert(i);
  }
  
  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int pos, val;
      cin >> pos >> val;
      poz[a[pos]].erase(pos);
      poz[a[pos] = val].insert(pos);
    } else {
      int l, r;
      cin >> l >> r;
      solve(l, r);
      if(gasit == 0) {
        cout << "0 0 0\n";
      }
      gasit = 0;
    }
  }
  return 0;
}
