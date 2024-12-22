// Fie num_trasee[i] = numarul de trasee de la (0, 0) la (i, i). Raspunsul va fi
// num_trasee[x]. (num_trasee[0] = 1)

// Pentru a calcula num_trasee[i], vom fixa cel mai recent j la care am facut
// plinul (acest j va fi la distanta maxim k/2 de i pentru ca noi trebuie sa
// ajungem de la j la i fara sa ni se termine benzina).

// num_trasee[i] += num_trasee[j] * 2 * catalan(i - j - 1), pentru fiecare j
// care respecta conditile j < i si 2 * (i - j) <= k (avem un -1 la formula
// pentru ca pozitiile (i,i) si (j,j) nu se numara ca acolo facem plinul)

#include <stdio.h>

const int MAXX = 50'000;
const int MOD = 997;
const int MAXCOMB = 2 * MAXX;

FILE *fin, *fout;
int num_trasee[MAXX + 1], k, x, fact[MAXCOMB + 1], invfact[MAXCOMB + 1];
char blocked[MAXX + 1];

void openFiles() {
  fin = fopen("calatorie.in", "r");
  fout = fopen("calatorie.out", "w");
}

void readData() {
  int n, i, val;
  fscanf(fin, "%d%d%d", &x, &k, &n);
  for(i = 0; i < n; i++) {
    fscanf(fin, "%d", &val);
    blocked[val] = 1;
  }
}

long long lgput(long long a, long long n, long long mod) {
  long long r = 1;
  while(n > 0) {
    if(n & 1) {
      r = (__int128)r * a % mod;
    }
    a = (__int128)a * a % mod;
    n >>= 1;
  }
  return r;
}

long long modularInverse(long long value, long long modulo) {
  return lgput(value, modulo - 2, modulo);
}

void computeFactorials() {
  int i;
  fact[0] = invfact[0] = 1;
    for(i = 1; i <= MAXCOMB; i++) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
    invfact[i] = modularInverse(fact[i], MOD);
  }
}

// Number of ways to choose k out of n identical objects
int comb(int n, int k) {
  if(n < k) {
    return 0;
  }
  return 1LL * fact[n] * invfact[n - k] % MOD * invfact[k] % MOD;
}

// Number of ways to choose k out of n different objects
int aranj(int n, int k) {
  if(n < k) {
    return 0;
  }
  return 1LL * fact[n] * invfact[n - k] % MOD;
}

int catalan(int k) {
  return 1LL * fact[2 * k] * invfact[k] * invfact[k + 1] % MOD;
}

void computeTrasee() {
  int i, j;
  num_trasee[0] = 1;
  for(i = 1; i <= x; i++) {
    num_trasee[i] = 0;
    if(!blocked[i]) {
      j = i - 1;
      while(j >= 0 && 2 * (i - j) <= k) {
        num_trasee[i] += num_trasee[j] * 2 * catalan(i - j - 1);
        j--;
      }
      num_trasee[i] %= MOD;
    }
  }
}

void writeAnswer() {
  fprintf(fout, "%d\n", num_trasee[x]);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readData();
  computeFactorials();
  computeTrasee();
  writeAnswer();
  closeFiles();
  return 0;
}
