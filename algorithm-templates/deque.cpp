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
};
