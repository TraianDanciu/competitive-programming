#include <stdio.h>
#include <vector>

#define MAXN 2000

char s[MAXN + 1];
std::vector<int> liste[MAXN + 1];

int main() {
  int n, k, i;
  long long ans;
  
  scanf("%d%d ", &n, &k);
  for(i = 1; i <= n; i++) {
    s[i] = fgetc(stdin) - 'a';
  }
  
  liste[0] = {1};
  liste[1] = {2};
  ans = 0;
  for(i = 2; i <= n; i++) {
    if(s[i] == s[i - 1]) {
      liste[i] = liste[i - 1];
      liste[i].back()++;
    } else {
      liste[i] = liste[i - 2];
      liste[i].push_back(i + 1);
    }
    
    if((int)liste[i].size() > k) {
      ans += liste[i][liste[i].size() - k - 1];
    }
  }
  
  printf("%lld\n", ans);
  return 0;
}
