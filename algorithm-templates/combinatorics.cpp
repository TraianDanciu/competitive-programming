int fact[MAXN + 1], invfact[MAXN + 1];

long long lgput(long long a, long long n, long long mod) {
  long long r = 1;
  while(n > 0) {
    if(n & 1) {
      r = (__int128)r * a % mod;
    }
    a = (__int128)a * a % mod;
    n >>= 1;
  }
  return r;
}

long long modularInverse(long long value, long long modulo) {
  return lgput(value, modulo - 2, modulo);
}

void computeFactorials() {
  int i;
  fact[0] = 1;
  for(i = 1; i <= MAXN; i++) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
  invfact[MAXN] = modularInverse(fact[MAXN], MOD);
  for(i = MAXN - 1; i >= 0; i--) {
    invfact[i] = 1LL * invfact[i + 1] * (i + 1) % MOD;
  }
}

// Number of ways to choose k out of n identical objects
int comb(int n, int k) {
  if(n < k) {
    return 0;
  }
  return 1LL * fact[n] * invfact[n - k] % MOD * invfact[k] % MOD;
}

// Number of ways to choose k out of n different objects
int aranj(int n, int k) {
  if(n < k) {
    return 0;
  }
  return 1LL * fact[n] * invfact[n - k] % MOD;
}
