#include <stdio.h>

const int MAXN = 5'000;
const int QSIZE = 1 << 25;
const int NDIR = 4;
const int DLIN[NDIR] = {-1, 0, 1, 0};
const int DCOL[NDIR] = {0, 1, 0, -1};
const int MAXK = 50'000;

FILE *fin, *fout;
char blocked[MAXN + 2][MAXN + 2], vfl[MAXN + 1], vfc[MAXN + 1];
int n, m, dist[MAXN + 2][MAXN + 2], l1, c1, l2, c2;
int k, lwall[MAXK], cwall[MAXK], sumvfl[MAXN + 1], sumvfc[MAXN + 1];

// QSIZE is the maximum length of the deque at all times
// It is recommended that QSIZE is an power of two (for better speed)
struct Deque {
  struct Node {
    int l, c;
  } v[QSIZE];
  int prim, ultim;

  void init() {
    prim = ultim = 0;
  }

  void pushFront(Node val) {
    prim = (prim - 1 + QSIZE) % QSIZE;
    v[prim] = val;
  }

  void pushBack(Node val) {
    v[ultim] = val;
    ultim = (ultim + 1) % QSIZE;
  }

  void popFront() {
    prim = (prim + 1) % QSIZE;
  }

  void popBack() {
    ultim = (ultim - 1 + QSIZE) % QSIZE;
  }

  Node front() {
    return v[prim];
  }

  Node back() {
    return v[(ultim - 1 + QSIZE) % QSIZE];
  }

  int empty() {
    return prim == ultim;
  }
} queue;

void openFiles() {
  fin = fopen("labir.in", "r");
  fout = fopen("labir.out", "w");
}

void readData() {
  int i;
  fscanf(fin, "%d%d%d%d%d%d%d", &n, &m, &l1, &c1, &l2, &c2, &k);
  vfl[l1] = vfl[l2] = vfc[c1] = vfc[c2] = 1;
  for(i = 0; i < k; i++) {
    fscanf(fin, "%d%d", &lwall[i], &cwall[i]);
    vfl[lwall[i]] = vfc[cwall[i]] = 1;
  }
}

void compressMatrix() {
  int l, c, cnt, i;

  cnt = 0;
  for(l = 1; l <= n; l++) {
    if(vfl[l - 1] == 0 && vfl[l] == 0) {
      cnt++;
    }
    sumvfl[l] = cnt;
  }

  cnt = 0;
  for(c = 1; c <= m; c++) {
    if(vfc[c - 1] == 0 && vfc[c] == 0) {
      cnt++;
    }
    sumvfc[c] = cnt;
  }

  l1 -= sumvfl[l1];
  c1 -= sumvfc[c1];
  l2 -= sumvfl[l2];
  c2 -= sumvfc[c2];
  for(i = 0; i < k; i++) { 
    lwall[i] -= sumvfl[lwall[i]];
    cwall[i] -= sumvfc[cwall[i]];
    blocked[lwall[i]][cwall[i]] = 1;
  }

  n -= sumvfl[n];
  m -= sumvfc[m];
}

void resetDist() {
  int l, c;
  for(l = 1; l <= n; l++) {
    for(c = 1; c <= m; c++) {
      dist[l][c] = -1;
    }
  }
  dist[l1][c1] = blocked[l1][c1];
}

void computeDist() {
  int l, c, dir, newl, newc;
  Deque::Node node;
  queue.pushFront({l1, c1});
  while(!queue.empty()) {
    node = queue.front();
    queue.popFront();
    l = node.l;
    c = node.c;
    for(dir = 0; dir < NDIR; dir++) {
      newl = l + DLIN[dir];
      newc = c + DCOL[dir];
      if(dist[newl][newc] == -1) {
        dist[newl][newc] = dist[l][c] + blocked[newl][newc];
        if(blocked[newl][newc]) {
          queue.pushBack({newl, newc});
        } else {
          queue.pushFront({newl, newc});
        }
      }
    }
  }
}

void writeAnswer() {
  fprintf(fout, "%d\n", dist[l2][c2]);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readData();
  compressMatrix();
  resetDist();
  computeDist();
  writeAnswer();
  closeFiles();
  return 0;
}
