#include <stdio.h>

const int MAXN = 500'000;
const int AINTN = 1 << 19;
const int T_UPDATE = 1;
const int T_QUERY = 2;
const int MAX_LEN = 5;

int n, q, v[MAXN], to_check[MAX_LEN];

int nextp2(int n) {
  while(n & (n - 1)) {
    n += n & -n;
  }
  return n;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int checkSequence(int len) {
  int i, ok, st, dr, found, target;

  if(len <= 2) {
    return 0;
  }

  ok = 0;
  for(i = 0; i < len; i++) {
    if(to_check[i] != 1) {
      ok = 1;
    }
  }


  st = 0;
  while(st < len - 2 && ok) {
    dr = st + 2;
    while(dr < len && ok) {
      target = max(to_check[st], to_check[dr]) / gcd(to_check[st], to_check[dr]);

      found = 0;
      i = st + 1;
      while(i < dr && found == 0) {
        if(to_check[i] == target) {
          found = 1;
        }
        i++;
      }
      if(found == 0) {
        ok = 0;
      }

      dr++;
    }

    st++;
  }

  return ok;
}

struct SegmentTree {
  struct Node {
    int pref_one, suff_one, node_len, pref[MAX_LEN], suff[MAX_LEN];
    long long num_seq;

    void join(Node a, Node b) {
      int i, num_left, num_right, stop_left, stop_right, a_suff;
      node_len = a.node_len + b.node_len;
    
      num_seq = a.num_seq + b.num_seq + 1LL * a.suff_one * b.pref_one;
      if(a.suff_one > 0 && b.pref_one > 0) {
        num_seq--; // Scad secventa de lungime 2 de la mijloc (daca exista)
      }

      if(a.pref_one == a.node_len) { // Daca a e plin de 1
        pref_one = a.node_len + b.pref_one;
      } else {
        pref_one = a.pref_one;
      }

      if(b.suff_one == b.node_len) { // Daca b e plin de 1
        suff_one = b.node_len + a.suff_one;
      } else {
        suff_one = b.suff_one;
      }

      if(a.node_len >= MAX_LEN) {
        for(i = 0; i < MAX_LEN; i++) {
          pref[i] = a.pref[i];
        }
      } else {
        for(i = 0; i < a.node_len; i++) {
          pref[i] = a.pref[i];
        }

        stop_left = min(MAX_LEN - a.node_len, b.node_len);
        for(i = 0; i < stop_left; i++) {
          pref[a.node_len + i] = b.pref[i];
        }
      }

      a_suff = min(MAX_LEN, a.node_len);
      if(b.node_len >= MAX_LEN) {
        for(i = 0; i < MAX_LEN; i++) {
          suff[i] = b.suff[i];
        }
      } else {
        stop_right = min(MAX_LEN - b.node_len, a.node_len);
        for(i = 0; i < stop_right; i++) {
          suff[i] = a.suff[i + a_suff - stop_right];
        }

        for(i = 0; i < b.node_len; i++) {
          suff[i + stop_right] = b.suff[i];
        }
      }

      stop_left = min(MAX_LEN - 1, a.node_len);
      for(num_left = 1; num_left <= stop_left; num_left++) {
        for(i = 0; i < num_left; i++) {
          to_check[i] = a.suff[i + a_suff - num_left];
        }
      
        stop_right = min(MAX_LEN - num_left, b.node_len);
        for(num_right = 1; num_right <= stop_right; num_right++) {
          to_check[num_left + num_right - 1] = b.pref[num_right - 1];
          num_seq += checkSequence(num_left + num_right);
        }
      }
    }
  } tree[AINTN << 1];
  int n;

  void init(int n) {
    int i;
    this->n = nextp2(n);
    for(i = 0; i < n; i++) {
      tree[this->n + i].node_len = 1;
      tree[this->n + i].num_seq = 0;
      if(v[i] == 1) {
        tree[this->n + i].pref_one = 1;
        tree[this->n + i].suff_one = 1;
      } else {
        tree[this->n + i].pref_one = 0;
        tree[this->n + i].suff_one = 0;
      }
      tree[this->n + i].pref[0] = v[i];
      tree[this->n + i].suff[0] = v[i];
    }
    for(i = n; i < this->n; i++) {
      tree[this->n + i].node_len = 0;
      tree[this->n + i].num_seq = 0;
    }
    for(i = this->n - 1; i > 0; i--) {
      tree[i].join(tree[2 * i], tree[2 * i + 1]);
    }
  }

  void update(int poz, int val) {
    poz += n;
    if(val == 1) {
      tree[poz].pref_one = 1;
      tree[poz].suff_one = 1;
    } else {
      tree[poz].pref_one = 0;
      tree[poz].suff_one = 0;
    }
    tree[poz].pref[0] = val;
    tree[poz].suff[0] = val;
    for(poz >>= 1; poz > 0; poz >>= 1) {
      tree[poz].join(tree[2 * poz], tree[2 * poz + 1]);
    }
  }

  long long query(int st, int dr) {
    Node rez_st, rez_dr;

    st += n;
    dr += n;

    rez_st.node_len = rez_st.num_seq = rez_st.pref_one = rez_st.suff_one = 0;
    rez_dr.node_len = rez_dr.num_seq = rez_dr.pref_one = rez_dr.suff_one = 0;
    while(st <= dr) {
      if(st & 1) {
        rez_st.join(rez_st, tree[st++]);
      }
      st >>= 1;

      if(!(dr & 1)) {
        rez_dr.join(tree[dr--], rez_dr);
      }
      dr >>= 1;
    }

    rez_st.join(rez_st, rez_dr);
    return rez_st.num_seq;
  }
} aint;

void readArray() {
  int i;
  scanf("%d%d", &n, &q);
  for(i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
}

void processOps() {
  int st, dr, type, poz, val;
  printf("%lld\n", aint.query(0, n - 1));
  while(q--) {
    scanf("%d", &type);
    if(type == T_UPDATE) {
      scanf("%d%d", &poz, &val);
      aint.update(--poz, val);
    } else { // T_QUERY
      scanf("%d%d", &st, &dr);
      st--;
      dr--;
      printf("%lld\n", aint.query(st, dr));
    }
  }
}

int main() {
  readArray();
  aint.init(n);
  processOps();
  return 0;
}
