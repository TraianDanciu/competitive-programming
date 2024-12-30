struct DSU {
  int sef[MAXN], card[MAXN];

  void init(int n) {
    int i;
    for(i = 0; i < n; i++) {
      card[i] = 1;
      sef[i] = i;
    }
  }

  int find(int i) {
    if(i == sef[i]) {
      return i;
    }
    return sef[i] = find(sef[i]);
  }

  void join(int i, int j) {
    if((i = find(i)) != (j = find(j))) {
      if(card[i] < card[j]) {
        std::swap(i, j);
      }
      card[i] += card[j];
      sef[j] = i;
    }
  }
};
