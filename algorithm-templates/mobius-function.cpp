int mobius[MAXN + 1];

void computeMobius() {
  int i, j;
  for(i = 1; i <= MAXN; i++) {
    mobius[i] = 1;
  }
  for(i = 2; i * i <= MAXN; i++) {
    if(mobius[i] == 1) {
      for(j = i; j <= MAXN; j += i) {
        mobius[j] *= -i;
      }
      for(j = i * i; j <= MAXN; j += i * i) {
        mobius[j] = 0;
      }
    }
  }
  for(i = 2; i <= MAXN; i++) {
    if(mobius[i] == i) {
      mobius[i] = 1;
    } else if(mobius[i] == -i) {
      mobius[i] = -1;
    } else if(mobius[i] < 0) {
      mobius[i] = 1;
    } else if(mobius[i] > 0) {
      mobius[i] = -1;
    }
  }
}
