// Voi rezolva problema inversa, adica voi calcula cate muchii de la un i la un j pot adauga
// astfel incat dist_src[i] + dist_dest[j] + 1 < dist_src_dest, iar daca fixam i, obtinem ca
// dist_dest[j] <= dist_src_dest - dist_src[i] - 2.

#include <stdio.h>
#include <vector>

const int MAXN = 100'000;
const int QSIZE = 1 << 17;

std::vector<int> g[MAXN];
int dist_src[MAXN], dist_dest[MAXN], n, m, src, dest, freq[MAXN];
long long answer;

// QSIZE is the maximum length of the deque at all times
// It is recommended that QSIZE is an power of two (for better speed)
struct Deque {
  struct Node {
    int val;
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

void readGraph() {
  int i, u, v;
  scanf("%d%d", &n, &m);
  for(i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  src = 0;
  dest = n - 1;
}

void bfsDistances(int source, int dist[MAXN]) {
  int node, i;
  for(i = 0; i < n; i++) {
    dist[i] = -1;
  }
  dist[source] = 0;
  queue.pushBack({source});
  while(!queue.empty()) {
    node = queue.front().val;
    queue.popFront();
    for(i = 0; i < (int)g[node].size(); i++) {
      if(dist[g[node][i]] == -1) {
        queue.pushBack({g[node][i]});
        dist[g[node][i]] = 1 + dist[node];
      }
    }
  }
}

void computeAnswer() {
  int i;

  for(i = 0; i < n; i++) {
    if(dist_dest[i] <= dist_src[dest]) {
      freq[dist_dest[i]]++;
    }
  }
  for(i = 1; i <= dist_src[dest]; i++) {
    freq[i] += freq[i - 1];
  }
  
  answer = 1LL * n * (n - 1) / 2 - m;
  for(i = 0; i < n; i++) {
    if(dist_src[dest] >= dist_src[i] + 2) {
      answer -= freq[dist_src[dest] - dist_src[i] - 2];
    }
  }
}

void writeAnswer() {
  printf("%lld\n", answer);
}

int main() {
  readGraph();
  bfsDistances(src, dist_src);
  bfsDistances(dest, dist_dest);
  computeAnswer();
  writeAnswer();
  return 0;
}
