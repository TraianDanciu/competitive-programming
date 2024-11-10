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
