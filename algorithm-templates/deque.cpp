// QSIZE is the maximum length of the deque at all times
struct Deque {
  struct Node {
    int lin, col;
  } v[QSIZE];
  int prim, ultim;

  void init() {
    prim = ultim = 0;
  }

  void pushFront(int lin, int col) {
    prim = (prim - 1 + QSIZE) % QSIZE;
    v[prim] = {lin, col};
  }

  void pushBack(int lin, int col) {
    v[ultim] = {lin, col};
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
};
