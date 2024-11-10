struct FenwickTree {
  int n;
  long long aib[MAXN + 1];

  // Initialises with the array "v" 
  void init(int n) {
    int i;
    this->n = n;
    for(i = 1; i <= n; i++) {
      aib[i] += v[i];
      if(i + (i & -i) <= n) {
        aib[i + (i & -i)] += aib[i];
      }
    }
  }

  // Add val to v[poz]
  void update(int poz, int val) {
    do {
      aib[poz] += val;
      poz += poz & -poz;
    } while(poz <= n);
  }

  // Sum of v[1] + v[2] + .. + v[poz]
  long long query(int poz) {
    long long rez = 0;
    while(poz > 0) {
      rez += aib[poz];
      poz &= poz - 1;
    }
    return rez;
  }
};
