#include "game.h"
#include <set>

#define MAXN 10000
#define MAXK 20

int n, k, which[MAXN + 1], st[MAXK + 1], dr[MAXK + 1], val[MAXK + 1];
std::set<std::pair<int, int>> intervals;

static inline int min(int a, int b) {
  return a < b ? a : b;
}

static inline void addInterval(int a, int b) {
  if(!intervals.count(std::make_pair(a, b))) {
    intervals.insert(std::make_pair(a, b));
    chooseInterval(a, b);
  }
}

int lstep, rstep;
void divideInit(int left, int right) {
  int middle, i;

  if(right - left <= 1) {
    addInterval(left, left);
    addInterval(right, right);
  } else {
    middle = (left + right) / 2;
    for(i = left; i <= middle; i++) {
      if((middle - i) % lstep == 0) {
        addInterval(i, middle);
      }
    }
    for(i = middle + 1; i <= right; i++) {
      if((i - middle - 1) % rstep == 0) {
        addInterval(middle + 1, i);
      }
    }
    
    divideInit(left, middle - 1);
    divideInit(middle + 2, right);
  }
}

void init(int _n, int _k) {
  int i, j, szbucket;

  n = _n;
  k = _k;

  if(k == 1) {
    for(i = 1; i <= n; i++) {
      for(j = i; j <= n; j++) {
        chooseInterval(i, j);
      }
    } 
  } else {
    // k - 2 pentru ca am un prefix si un sufix si dupa
    // dau ce a mai ramas cate jumate in fiecare parte
    // dupa adun inca 1 in fiecare parte pt prefix/sufix
    lstep = (k - 2) / 2 + 1;
    rstep = (k - 1) / 2 + 1;
    divideInit(1, n);
  }
}

void divideSolve(int left, int right, int a, int b) {
  int middle;

  if(right - left <= 1) {
    chooseInterval(a, a);
    if(a != b) {
      chooseInterval(b, b);
    }
  } else {
    middle = (left + right) / 2;

    if(a <= middle && middle < b) {
      while((middle - a) % lstep) {
        chooseInterval(a, a);
        a++;
      }
      chooseInterval(a, middle);
      while((b - middle - 1) % rstep) {
        chooseInterval(b, b);
        b--;
      }
      chooseInterval(middle + 1, b);
    } else if(a <= middle) {
      if(b == middle) {
        while((middle - a) % lstep) {
          chooseInterval(a, a);
          a++;
        }
        chooseInterval(a, b);
      } else {
        divideSolve(left, middle - 1, a, b);
      }
    } else {
      if(a == middle + 1) {
        while((b - middle - 1) % rstep) {
          chooseInterval(b, b);
          b--;
        }
        chooseInterval(a, b);
      } else {
        divideSolve(middle + 2, right, a, b);
      }
    }
  }
}

void query(int a, int b) {
  if(k == 1) {
    chooseInterval(a, b);
  } else {
    divideSolve(1, n, a, b);
  }
}
