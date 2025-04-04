// Este trivial de demonstrat ca p <= n. Pentru p < 3200 facem brut,
// iar pentru p >= 3200, p^2 > n asa ca el ar putea fi doar egal cu p
// (verificam daca n e prim) sau egal cu 1+p (verificam daca n-1 e
// prim)

#include <stdio.h>

const int LIMIT_BRUTE = 3'200;

FILE *fin, *fout;
int n, prime1, prime2, ciur[LIMIT_BRUTE];

void openFiles() {
  fin = fopen("desc.in", "r");
  fout = fopen("desc.out", "w");
}

void readData() {
  fscanf(fin, "%d", &n);
}

void solveBrute() {
  int p, distinct_powers, copie, cnt, rest, multiplu;
  prime1 = prime2 = 1;
  for(p = 2; p < LIMIT_BRUTE; p++) {
    if(ciur[p] == 0) { // Daca p e prim
      for(multiplu = p * p; multiplu < LIMIT_BRUTE; multiplu += p) {
        ciur[multiplu] = 1;
      }

      // Verificam daca n si n-1 sunt prime pentru solveSmart
      if(n % p == 0) {
        prime1 = 0;
      }
      if((n - 1) % p == 0) {
        prime2 = 0;
      }
      
      copie = n;
      distinct_powers = 1;
      cnt = 0;
      while(copie > 0) {
        rest = copie % p;
        copie /= p;
        if(rest > 1) {
          distinct_powers = 0;
        } else if(rest == 1) {
          cnt++;
        }
      }

      if(distinct_powers) {
        fprintf(fout, "%d %d", p, cnt);
        copie = n;
        cnt = 0;
        while(copie > 0) {
          if(copie % p > 0) {
            fprintf(fout, " %d", cnt);
          }
          cnt++;
          copie /= p;
        }
        fputc('\n', fout);
      }
    }
  }
}

void solveSmart() {
  if(n > LIMIT_BRUTE) {
    if(prime1) {
      fprintf(fout, "%d 1 1\n", n);
    }
    if(prime2) {
      fprintf(fout, "%d 2 0 1\n", n - 1);
    }
  }
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readData();
  solveBrute();
  solveSmart();
  closeFiles();
  return 0;
}
