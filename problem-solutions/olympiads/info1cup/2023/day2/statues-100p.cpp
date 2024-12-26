#include <stdio.h>
#include <algorithm>

static inline long long max(long long a, long long b) {
  return a > b ? a : b;
}

#define MAXQ 200000
#define MOD 1000003

int lgpow(int a, int n) {
  int r = 1;
  while(n > 0) {
    if(n % 2) {
      r = 1LL * r * a % MOD;
    }
    a = 1LL * a * a % MOD;
    n /= 2;
  }
  return r;
}

int cnt, fact[MOD], invfact[MOD];
long long x[MAXQ], y[MAXQ], v[2 * MAXQ + 2];

int cb(long long val) {
  int st, dr, mij;

  st = -1;
  dr = cnt - 1;
  while(dr - st > 1) {
    mij = (st + dr) / 2;
    if(v[mij] < val) {
      st = mij;
    } else {
      dr = mij;
    }
  }

  return dr;
}

long long aint[8 * MAXQ], qval;
int qleft, qright, qpos;

void _update(int node, int left, int right) {
  int middle;

  if(qleft <= left && right <= qright) {
    aint[node] = max(aint[node], qval);
  } else {
    middle = (left + right) / 2;
    if(qleft <= middle) {
      _update(2 * node + 1, left, middle);
    }
    if(middle < qright) {
      _update(2 * node + 2, middle + 1, right);
    }
  }
}
static inline void update(int _qleft, int _qright, long long _qval) {
  qleft = _qleft;
  qright = _qright;
  qval = _qval;
  _update(0, 0, cnt - 1);
}

long long _query(int node, int left, int right) {
  int middle;
  long long ans;

  ans = aint[node];
  if(left < right) {
    middle = (left + right) / 2;
    if(qpos <= middle) {
      ans = max(ans, _query(2 * node + 1, left, middle));
    } else { 
      ans = max(ans, _query(2 * node + 2, middle + 1, right));
    }
  }
  
  return ans;
}
static inline long long query(int _qpos) {
  qpos = _qpos;
  return _query(0, 0, cnt - 1);
}

int main() {
  int q, i, ans;
  long long n, qry, a, b;

  fact[0] = 1;
  for(i = 1; i < MOD; i++) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
  invfact[MOD - 1] = lgpow(fact[MOD - 1], MOD - 2);
  for(i = MOD - 2; i >= 0; i--) {
    invfact[i] = 1LL * invfact[i + 1] * (i + 1) % MOD;
  }
  
  scanf("%lld%d", &n, &q);
  v[cnt++] = 1;
  for(i = 0; i < q; i++) {
    scanf("%lld%lld", &x[i], &y[i]);
    v[cnt++] = x[i];
    v[cnt++] = y[i] + 1;
  }
  v[cnt++] = n + 1;

  std::sort(v, v + cnt);
  cnt = std::unique(v, v + cnt) - v;

  update(0, cnt - 1, 1);
  for(i = 0; i < q; i++) {
    update(cb(x[i]), cb(y[i] + 1) - 1, x[i]);
  }

  ans = 1;
  for(i = 0; i < cnt - 1; i++) {
    qry = query(i);
    a = v[i + 1] - qry;
    b = v[i] - qry;
    if(a / MOD >= (b + MOD) / MOD) {
      ans = 0;
    } else {
      ans = 1LL * ans * fact[a % MOD] * invfact[b % MOD] % MOD;
    }
  }
  
  printf("%d\n", ans);
  return 0;
}
