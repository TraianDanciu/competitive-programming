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
