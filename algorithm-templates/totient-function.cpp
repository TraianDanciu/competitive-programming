int phi[MAXN + 1];

void computePhi() {
  int i, j;
  for(i = 1; i <= MAXN; i++) {
    phi[i] = i;
  }
  for(i = 2; i <= MAXN; i++) {
    if(phi[i] == i) {
      for(j = i; j <= MAXN; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}
