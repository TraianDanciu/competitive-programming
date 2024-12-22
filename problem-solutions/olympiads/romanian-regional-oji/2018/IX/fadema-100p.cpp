#include <stdio.h>

const int MAXN = 1'000;

FILE *fin, *fout;
char mat[MAXN][MAXN];
int n, m, height[MAXN + 2], stiva[MAXN + 1], st[MAXN + 1];

void openFiles() {
  fin = fopen("fadema.in", "r");
  fout = fopen("fadema.out", "w");
}

void readData() {
  int l, c;
  fscanf(fin, "%d%d", &n, &m);
  for(l = 0; l < n; l++) {
    for(c = 0; c < m; c++) {
      fscanf(fin, "%hhd", &mat[l][c]);
    }
  }
}

void makeDiagonals() {
  int l, c;
  for(l = 0; l < n; l++) {
    for(c = 0; c < m; c++) {
      mat[l][c] ^= (l + c) % 2;
    }
  }
}

int max(int a, int b) {
  return a > b ? a : b;
}

int maxRectangle(int val) {
  int l, c, sp, answer = 0, dr;
  for(l = 0; l < n; l++) {
    for(c = 0; c < m; c++) {
      if(mat[l][c] == val) {
        height[c + 1]++;
      } else {
        height[c + 1] = 0;
      }
    }

    height[0] = -1;
    stiva[0] = 0;
    sp = 1;
    for(c = 1; c <= m; c++) {
      while(height[stiva[sp - 1]] >= height[c]) {
        sp--;
      }
      st[c] = stiva[sp - 1] + 1;
      stiva[sp++] = c;
    }

    height[m + 1] = -1;
    stiva[0] = m + 1;
    sp = 1;
    for(c = m; c >= 1; c--) {
      while(height[stiva[sp - 1]] >= height[c]) {
        sp--;
      }
      dr = stiva[sp - 1] - 1;
      answer = max(answer, (dr - st[c] + 1) * height[c]);
      stiva[sp++] = c;
    }
  }
  return answer;
}

void writeAnswer(int answer) {
  fprintf(fout, "%d\n", answer);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  readData();
  makeDiagonals();
  writeAnswer(max(maxRectangle(0), maxRectangle(1)));
  closeFiles();
  return 0;
}
