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

// Using Fermat's little theorem. Works only when modulo is prime
long long modularInverse(long long value, long long modulo) {
  return lgput(value, modulo - 2);
}

long long extendedGcd(long long a, long long b, long long &x, long long &y) {
  long long d, x0, y0;
  
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  d = extendedGcd(b, a % b, x0, y0);
  x = y0;
  y = x0 - (a / b) * y0;
  return d;
}

// Using extended gcd
long long modularInverse(long long value, long long modulo) {
  long long x, y;
  extendedGcd(value, modulo, x, y);
  x %= modulo;
  if(x < 0) {
    x += modulo;
  }
  return x;
}
