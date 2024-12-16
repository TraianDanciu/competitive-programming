#include <stdio.h>

const int MAXVAL = 32'000;

int n, k, mobius[MAXVAL + 1], answer;
FILE *fin, *fout;

void openFiles() {
  fin = fopen("cardinal.in", "r");
  fout = fopen("cardinal.out", "w");
}

void readData() {
  fscanf(fin, "%d%d", &n, &k);
}

void computeMobius() {
  int i, j;
  for(i = 1; i <= MAXVAL; i++) {
    mobius[i] = 1;
  }
  for(i = 2; i * i <= MAXVAL; i++) {
    if(mobius[i] == 1) {
      for(j = i; j <= MAXVAL; j += i) {
        mobius[j] *= -i;
      }
      for(j = i * i; j <= MAXVAL; j += i * i) {
        mobius[j] = 0;
      }
    }
  }
  for(i = 2; i <= MAXVAL; i++) {
    if(mobius[i] == i) {
      mobius[i] = 1;
    } else if(mobius[i] == -i) {
      mobius[i] = -1;
    } else if(mobius[i] < 0) {
      mobius[i] = 1;
    } else if(mobius[i] > 0) {
      mobius[i] = -1;
    }
  }
}

long long power(int a, int n) {
  int i;
  long long r = 1;
  for(i = 0; i < n; i++) {
    r *= a;
  }
  return r;
}

void computeAnswer() {
  int i;
  long long aux;
  answer = n - 1;
  i = 2;
  while((aux = power(i, k + 1)) <= n) {
    answer += mobius[i++] * (n / aux);
  }
}

void writeAnswer() {
  fprintf(fout, "%d\n", answer);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  readData();
  computeMobius();
  computeAnswer();
  writeAnswer();
  closeFiles();
  return 0;
}
