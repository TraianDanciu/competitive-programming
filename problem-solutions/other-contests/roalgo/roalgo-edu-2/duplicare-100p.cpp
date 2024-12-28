int duplicare(int n) {
  int pn = 1, pm = 1, m = 0, ok = 0;
  while(pn <= n) {
    if((n / pn) % 2) {
      m += pm * ((n / pn) % 10);
      pm *= 10;
      ok = 1;
    }
    m += pm * ((n / pn) % 10);
    pm *= 10;
    pn *= 10;
  }
  return ok ? m : -1;
}
