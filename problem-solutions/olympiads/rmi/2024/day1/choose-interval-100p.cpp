// Problema se transforma in mod trivial de la un sir infinit la un sir
// de la 0 la 2n (elementul 0 va reprezenta toate celelalte elemente care
// nu sunt in intervalul [1, 2n])

// Iau mai intai intervalele pe exterior. Apoi, cand vreau sa ma razgandesc
// la un interval, voi face -1 pe tot sirul si +2 in interiorul acelui
// interval.

// Dupa ce iau toate intervalele pe exterior, voi fixa la cate intervale
// ma voi razgandi (sa zicem k). Acum, voi face -k pe tot sirul si voi
// avea doar operatii de +2 pe interval.

// Dupa ce am fixat k, sa cautam binar raspunsul. Cand vrem sa verificam
// daca putem sa facem operatii pe cel putin k intervale si fiecare numar
// sa fie <= mij, voi calcula maxop[i] = cate operatii "suporta" elementul i.

// maxop[i] = (mij + k - v[i]) / 2. Acum, cand vreau sa vad daca pot sa 
// fac operatia pe un interval, trebuie sa am maxop[st..dr] >= 0, iar apoi
// o sa fac maxop[st..dr]--. Asta cam suna a aint cu lazy, nu? :)

// Dar in ce ordine o sa parcurg intervalele? Raspuns: in ordinea crescatoare
// a capetelor dreapta. De ce: Problema spectacolelor.

// Complexitatea ar fi O(n^2log^2). Dar observam ca maxop[i] nu depinde
// si de k si de mij, depinde doar de mij+k. Asa ca vom precalcula 
// rezultatele in functie de mij+k. Complexitatea va fi O(n^2log).

// Dar noi cand trecem de la un mij+k la un mij+k+2, vom face practic un
// ++ pe tot sirul. Dupa ce am procesat mij+k, toate intervalele care au
// fost alese vor fi alese si la mij+k+2. Iar in toate intervalele pe care
// nu le-am ales exista cate un 0.

// Dupa ce am trecut de la mij+k la mij+k+2 o sa iau orice interval care
// are capatul dreapta cat mai mic, apoi o sa iau orice interval cu capatul
// stanga mai mare decat capatul dreapta al celui anterior si cu capat
// dreapta minim si tot asa pana cand ajung la final. 

// Ca sa gasesc acest interval urmator o sa folosesc un alt arbore de
// intervale in care o sa imi tin intervalele sortate crescator in functie
// de capatul stanga, iar apoi voi intreba pe un sufix de intervalul cu
// capatul dreapta cel mai mic.

// Parcurgerea asta se amortizeaza, deoarece de fiecare data voi alege
// un interval care nu a mai fost ales, deci complexitatea va fi O(nlog),
// insa vom avea o constanta foarte proasta.

#include <stdio.h>
#include <algorithm>

const int MAXN = 200'000;
const int AINTN = 1 << 19;
const int INFINIT = 1'000'000'000;
const int AINTN_INTERVALS = 1 << 18;

int n, v[MAXN * 2 + 2], answer, answerk, maxop[2 * MAXN + 1], max_v,
  max_intervals[MAXN * 2 + 1], poz2[MAXN], first_after[2 * MAXN + 2];
char chosen_interval[MAXN];

struct Interval {
  int st, dr, index;
} intervals[MAXN], intervals2[MAXN];

int nextp2(int n) {
  while(n & (n - 1)) {
    n += n & -n;
  }
  return n;
}

int min(int a, int b) {
  return a < b ? a : b;
}

struct SegmentTree {
  struct Node {
    int minim, poz, lazy;

    void join(Node a, Node b) {
      if(a.minim < b.minim) {
        minim = a.minim;
        poz = a.poz;
      } else {
        minim = b.minim;
        poz = b.poz;
      }
    }
  } tree[AINTN << 1];
  int n;

  void init(int n) {
    int i;
    this->n = nextp2(n);
    for(i = 0; i < n; i++) {
      tree[this->n + i] = {maxop[i], i, 0};
    }
    for(i = n; i < this->n; i++) {
      tree[this->n + i] = {INFINIT, i, 0};
    }
    for(i = this->n - 1; i > 0; i--) {
      tree[i].join(tree[2 * i], tree[2 * i + 1]);
      tree[i].lazy = 0;
    }
  }

  void push(int node) {
    tree[2 * node].minim += tree[node].lazy;
    tree[2 * node].lazy += tree[node].lazy;
    tree[2 * node + 1].minim += tree[node].lazy;
    tree[2 * node + 1].lazy += tree[node].lazy;
    tree[node].lazy = 0;
  }

  void pushPath(int node) {
    int bits = 31 - __builtin_clz(node), b;
    for(b = bits; b > 0; b--) {
      push(node >> b);
    }
  }

  void pullPath(int node) {
    for(node >>= 1; node > 0; node >>= 1) {
      if(tree[node].lazy == 0) {
        tree[node].join(tree[2 * node], tree[2 * node + 1]);
      }
    }
  }
  
  void update(int st, int dr, int val) {
    int st_orig, dr_orig;
    
    st += n;
    dr += n;
    st_orig = st;
    dr_orig = dr;

    pushPath(st);
    pushPath(dr);

    while(st <= dr) {
      if(st & 1) {
        tree[st].minim += val;
        tree[st].lazy += val;
        st++;
      }
      st >>= 1;

      if(!(dr & 1)) {
        tree[dr].minim += val;
        tree[dr].lazy += val;
        dr--;
      }
      dr >>= 1;
    }

    pullPath(st_orig);
    pullPath(dr_orig);
  }

  Node query(int st, int dr) {
    Node rez1, rez2;

    st += n;
    dr += n;

    pushPath(st);
    pushPath(dr);

    rez1 = rez2 = {INFINIT, -1, 0};
    while(st <= dr) {
      if(st & 1) {
        rez1.join(rez1, tree[st++]);
      }
      st >>= 1;

      if(!(dr & 1)) {
        rez2.join(tree[dr--], rez2);
      }
      dr >>= 1;
    }

    rez1.join(rez1, rez2);
    return rez1;
  }
} aint;

struct SegmentTree2 {
  struct Node {
    int mindr, poz;

    void join(Node a, Node b) {
      if(a.mindr < b.mindr) {
        mindr = a.mindr;
        poz = a.poz;
      } else {
        mindr = b.mindr;
        poz = b.poz;
      }
    }
  } tree[AINTN_INTERVALS << 1];
  int n;

  void init(int n) {
    int i;
    this->n = nextp2(n);
    for(i = 0; i < n; i++) {
      tree[this->n + i] = {intervals2[i].dr, i};
    }
    for(i = n; i < this->n; i++) {
      tree[this->n + i] = {INFINIT, -1};
    }
    for(i = this->n - 1; i > 0; i--) {
      tree[i].join(tree[2 * i], tree[2 * i + 1]);
    }
  }

  void remove(int poz) {
    tree[poz += n] = {INFINIT, -1};
    for(poz >>= 1; poz > 0; poz >>= 1) {
      tree[poz].join(tree[2 * poz], tree[2 * poz + 1]);
    }
  }

  int query(int st, int dr) {
    Node rez;

    st += n;
    dr += n;

    rez = {INFINIT, -1};
    while(st <= dr) {
      if(st & 1) {
        rez.join(tree[st++], rez);
      }
      st >>= 1;

      if(!(dr & 1)) {
        rez.join(rez, tree[dr--]);
      }
      dr >>= 1;
    }

    return rez.poz;
  }
} aint_intervals;

void readData() {
  int i;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d%d", &intervals[i].st, &intervals[i].dr);
    intervals[i].index = i;
    intervals2[i] = intervals[i];
  }
}

void updateInterval(int st, int dr) {
  v[st]++;
  v[dr + 1]--;
}

void takeExteriorIntervals() {
  int i;
  for(i = 0; i < n; i++) {
    updateInterval(0, intervals[i].st - 1);
    updateInterval(intervals[i].dr + 1, 2 * n);
  }
  max_v = v[0];
  for(i = 1; i <= 2 * n; i++) {
    v[i] += v[i - 1];
    if(v[i] > max_v) {
      max_v = v[i];
    }
  }
}

void sortIntervals() {
  int i;

  std::sort(intervals, intervals + n, [](Interval a, Interval b) {
    return a.dr < b.dr;
  });
  std::sort(intervals2, intervals2 + n, [](Interval a, Interval b) {
    return a.st < b.st;
  });
  
  for(i = 0; i < n; i++) {
    poz2[intervals2[i].index] = i;
  }
  for(i = 0; i < n; i++) {
    intervals[i].index = poz2[intervals[i].index];
  }

  for(i = 0; i <= 2 * n + 1; i++) {
    first_after[i] = -1;
  }
  for(i = 0; i < n; i++) {
    if(first_after[intervals2[i].st] == -1) {
      first_after[intervals2[i].st] = i;
    }
  }
  for(i = 2 * n; i >= 0; i--) {
    if(first_after[i] == -1) {
      first_after[i] = first_after[i + 1];
    }
  }
}

int getIntervals(int val) {
  int i, cnt;
  for(i = 0; i <= 2 * n; i++) {
    maxop[i] = (val - v[i]) / 2;
  }
  aint.init(2 * n + 1);
  cnt = 0;
  for(i = 0; i < n; i++) {
    if(aint.query(intervals[i].st, intervals[i].dr).minim > 0) {
      aint.update(intervals[i].st, intervals[i].dr, -1);
      cnt++;
      chosen_interval[intervals[i].index] = 1;
    } else {
      chosen_interval[intervals[i].index] = 0;
    }
  }
  return cnt;
}

void computeMaxIntervals() {
  int parity, sum, last_dr, idx, cnt, i;
  for(parity = 0; parity < 2; parity++) {
    for(sum = parity; sum < max_v; sum += 2) {
      max_intervals[sum] = -1;
    }

    max_intervals[sum] = getIntervals(sum);
    aint_intervals.init(n);
    for(i = 0; i < n; i++) {
      if(chosen_interval[i]) {
        aint_intervals.remove(i);
      }
    }
    
    cnt = max_intervals[sum];
    for(sum += 2; sum <= 2 * n; sum += 2) {
      aint.update(1, 2 * n, +1);
      last_dr = 1;
      idx = 0;
      while(first_after[last_dr] != -1 && idx != -1) {
        idx = aint_intervals.query(first_after[last_dr], n - 1);
        if(idx != -1) {
          last_dr = aint.query(intervals2[idx].st, intervals2[idx].dr).poz + 1;
          aint.update(intervals2[idx].st, intervals2[idx].dr, -1);
          aint_intervals.remove(idx);
          cnt++;
        }
      }
      max_intervals[sum] = cnt;
    }
  }
}

void computeAnswer() {
  int k, st, dr, mij;
  answer = n;
  answerk = -1;
  for(k = 0; k <= n; k++) {
    st = 0;
    dr = n;
    while(dr - st > 1) {
      mij = (st + dr) / 2;
      if(max_intervals[k + mij] < k) {
        st = mij;
      } else {
        dr = mij;
      }
    }

    if(answer > dr) {
      answer = dr;
      answerk = k;
    }
  }
}

void reconstructSolution() {
  int i, cnt;
  
  for(i = 0; i < n; i++) {
    intervals[i].index = intervals2[intervals[i].index].index;
  }
  getIntervals(answerk + answer);

  cnt = 0;
  for(i = 0; i < n; i++) {
    if(chosen_interval[i]) {
      if(cnt == answerk) {
        chosen_interval[i] = 0;
      } else {
        cnt++;
      }
    }
  }
}

void writeAnswer() {
  int i;
  printf("%d\n", answer);
  for(i = 0; i < n; i++) {
    fputc('0' + chosen_interval[i], stdout);
  }
  fputc('\n', stdout);
}

int main() {
  readData();
  takeExteriorIntervals();
  sortIntervals();
  computeMaxIntervals();
  computeAnswer();
  reconstructSolution();
  writeAnswer();
  return 0;
}
