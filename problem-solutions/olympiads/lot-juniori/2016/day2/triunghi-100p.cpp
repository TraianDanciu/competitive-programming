// Fie max_triangle[i][j] = marimea triunghiului maximal care are coltul stanga
// jos la (i, j)

#include <stdio.h>

const int MAXN = 1'500;
const int MAXCOL = 2 * MAXN - 1;
const int INFINIT = 1'000'000'000;

FILE *fin, *fout;
int n, q, color[MAXN][MAXCOL], answer[MAXN], max_triangle[MAXN][MAXCOL];

void openFiles() {
  fin = fopen("triunghi.in", "r");
  fout = fopen("triunghi.out", "w");
}

void readData() {
  int i, m, l, c;
  fscanf(fin, "%d%d%d", &n, &m, &q);
  for(i = 0; i < m; i++) {
    fscanf(fin, "%d%d", &l, &c);
    color[l - 1][c - 1] = 1;
  }
}

int min(int a, int b) {
  return a < b ? a : b;
}

void computeTriangles() {
  int l, c, i;
  for(l = n - 1; l >= 0; l--) {
    for(c = 0; c <= 2 * l; c += 2) {
      if(color[l][c] == 0) {
        if(l < n - 1 && color[l + 1][c + 1] == 0) {
          max_triangle[l][c] = 1 + min(max_triangle[l + 1][c],
                                       max_triangle[l + 1][c + 2]);
        } else {
          max_triangle[l][c] = 1;
        }
      } else {
        max_triangle[l][c] = 0;
      }
      answer[max_triangle[l][c]]++;
    }
  }

  for(i = n - 1; i >= 0; i--) {
    answer[i] += answer[i + 1];
  }
}

void processQueries() {
  int val;
  while(q--) {
    fscanf(fin, "%d", &val);
    fprintf(fout, "%d\n", answer[val]);
  }
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readData();
  computeTriangles();
  processQueries();
  closeFiles();
  return 0;
}
