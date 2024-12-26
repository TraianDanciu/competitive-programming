#include <stdio.h>

const int MOD = 1'000'000'007;
const int MAXN = 250'000;
const int MAXVAL = 1 << 18;

int v[MAXN], n, p, sum_power[MAXVAL + 1], power[MAXVAL], answer;

void readData() {
  int i;
  scanf("%d%d", &n, &p);
  for(i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
}

int lgput(int a, int n) {
  int r = 1;
  while(n > 0) {
    if(n & 1) {
      r = 1LL * r * a % MOD;
    }
    a = 1LL * a * a % MOD;
    n >>= 1;
  }
  return r;
}

void computePowers() {
  int i;
  for(i = 0; i < MAXVAL; i++) {
    power[i] = lgput(i, p);
    sum_power[i + 1] = sum_power[i] + power[i];
    if(sum_power[i + 1] >= MOD) {
      sum_power[i + 1] -= MOD;
    }
  }
}

void computeAnswer() {
  int i, fixed_prefix, cleared, newi;
  long long answeri;
  for(i = 0; i < n; i++) {
    answeri = 0;
    for(fixed_prefix = 0; (1 << fixed_prefix) <= i; fixed_prefix++) {
      if(i & (1 << fixed_prefix)) { // ca sa taiem bitul
        newi = i ^ (1 << fixed_prefix);
        cleared = ((v[i] ^ newi) >> fixed_prefix) << fixed_prefix;
        answeri += sum_power[cleared + (1 << fixed_prefix)]
                                                - sum_power[cleared];
      }
    }
    answeri += power[v[i] ^ i];
    answer = (answer + answeri * (n - i)) % MOD;
  }
}

void writeAnswer() {
  if(answer < 0) {
    answer += MOD;
  }
  printf("%d\n", answer);
}

int main() {
  readData();
  computePowers();
  computeAnswer();
  writeAnswer();
  return 0;
}
