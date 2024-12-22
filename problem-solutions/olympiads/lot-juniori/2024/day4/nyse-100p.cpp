#include <stdio.h>
#include <algorithm>

#define MAXN 900000
#define LOGN 20

int p[MAXN], pnou[MAXN];
struct Element {
  int val, poz;
} v[MAXN];
static inline int compar(Element a, Element b) {
  return a.val < b.val;
}
short l[MAXN];
long long maxprofit[MAXN];

struct FenwickTree {
  long long aib[MAXN + 1];
  int n;

  void init(int n) {
    int i;
    
    this->n = n;
    for(i = 0; i <= n; i++) {
      aib[i] = 0;
    }
  }

  void update(int poz, long long val) {
    do {
      aib[poz] += val;
      poz += poz & -poz;
    } while(poz <= n);
  }

  long long query(int poz) {
    long long ans = 0;
    while(poz > 0) {
      ans += aib[poz];
      poz &= poz - 1;
    }
    return ans;
  }

  // cel mai mic indice cu suma partiala >=
  int cb(long long val) {
    int ans, i;

    if(val == 0) {
      return 0;
    }

    ans = 0;
    for(i = LOGN - 1; i >= 0; i--) {
      if(ans + (1 << i) <= n && val > aib[ans + (1 << i)]) {
        val -= aib[ans += 1 << i];
      }
    }
    
    return ans + 1;
  }
} aibl, aibp;

int main() {
  int n, i, q, st, dr, mij, cnt, lsum, jum, cate1, cate2;
  long long psum, pref1, pref2, suff, x;

  #ifndef LOCAL
    freopen("nyse.in", "r", stdin);
    freopen("nyse.out", "w", stdout);
  #endif

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    v[i] = (struct Element){.val = p[i], .poz = i};
  }
  for(i = 0; i < n; i++) {
    scanf("%hd", &l[i]);
  }

  std::sort(v, v + n, compar);
  pnou[v[0].poz] = cnt = 0;
  for(i = 1; i < n; i++) {
    if(v[i].val > v[i - 1].val) {
      v[++cnt] = v[i];
    }
    pnou[v[i].poz] = cnt;
  }

  lsum = psum = 0;
  aibl.init(cnt + 1);
  aibp.init(cnt + 1);
  for(i = 0; i < n; i++) {
    lsum += l[i];
    psum += 1LL * p[i] * l[i];
    aibl.update(pnou[i] + 1, l[i]); 
    aibp.update(pnou[i] + 1, 1LL * p[i] * l[i]);

    jum = aibl.cb((lsum + 1) / 2);
    if(jum > 0) {
      pref1 = aibl.query(jum - 1);
      pref2 = aibl.query(jum);
      suff = lsum - pref2;
      pref2 -= pref1;
      cate1 = (pref2 - pref1 + suff) / 2;
      cate2 = (pref2 + pref1 - suff) / 2;

      pref2 = aibp.query(jum - 1) + 1LL * cate1 * v[jum - 1].val;
      suff = psum - aibp.query(jum) + 1LL * cate2 * v[jum - 1].val;
      maxprofit[i] = suff - pref2;
    }
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%lld", &x);

    if(maxprofit[n - 1] < x) {
      printf("-1\n");
    } else {
      st = -1;
      dr = n - 1;
      while(dr - st > 1) {
        mij = (st + dr) / 2;
        if(maxprofit[mij] < x) {
          st = mij;
        } else {
          dr = mij;
        }
      }
      printf("%d\n", dr + 1);
    }
  }

  return 0;
}
