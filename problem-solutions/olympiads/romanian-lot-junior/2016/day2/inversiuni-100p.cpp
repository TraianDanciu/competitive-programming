#include <stdio.h>

static inline int min(int a, int b) {
  return a < b ? a : b;
}

#define NMAX 200000

int n, aib[NMAX + 1];

void update(int pos) {
  for (; pos <= n; pos += pos & -pos)
    aib[pos]++;
}

int query(int pos) {
  int ans = 0;
  for (; pos > 0; pos -= pos & -pos)
    ans += aib[pos];
  return ans;
}

int main() {
  FILE *fin, *fout;
  int i, x, cnt;
  long long ans;
  fin = fopen("inversiuni.in", "r");
  fscanf(fin, "%d", &n);
  ans = 0;
  for (i = 0; i < n; i++) {
    fscanf(fin, "%d", &x);
    cnt = query(x);
    ans += min(cnt, i - cnt); // am cnt mai mici, si i - cnt mai mari
    update(x);
  }
  fclose(fin);
  fout = fopen("inversiuni.out", "w");
  fprintf(fout, "%lld\n", ans);
  fclose(fout);
  return 0;
}
