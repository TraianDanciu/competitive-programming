#include <stdio.h>

#define NMAX 512

int mat[NMAX][NMAX], dlin[] = {0, 0, 1, 1}, dcol[] = {0, 1, 0, 1}, cnt;

void genPav(int lin, int col, int lat, int lhole, int chole) {
  int dir, newlin, newcol, aux;
  if (lat > 0) {
    aux = ++cnt;
    for (dir = 0; dir < 4; dir++) {
      newlin = lin + (dlin[dir] << (lat - 1));
      newcol = col + (dcol[dir] << (lat - 1));
      if (newlin + (1 << (lat - 1)) > lhole && newlin <= lhole &&
          newcol + (1 << (lat - 1)) > chole && newcol <= chole)
        genPav(newlin, newcol, lat - 1, lhole, chole);
      else {
        genPav(newlin, newcol, lat - 1,
               newlin + ((dlin[dir] ^ 1) << (lat - 1)) - (dlin[dir] ^ 1),
               newcol + ((dcol[dir] ^ 1) << (lat - 1)) - (dcol[dir] ^ 1));
        mat[newlin + ((dlin[dir] ^ 1) << (lat - 1)) - (dlin[dir] ^ 1)]
           [newcol + ((dcol[dir] ^ 1) << (lat - 1)) - (dcol[dir] ^ 1)] = aux;
      }
    }
  }
}

int main() {
  FILE *fin, *fout;
  int n, lin, col;
  fin = fopen("pav.in", "r");
  fscanf(fin, "%d%d%d", &n, &lin, &col);
  fclose(fin);
  genPav(0, 0, n, lin - 1, col - 1);
  fout = fopen("pav.out", "w");
  for (lin = 0; lin < (1 << n); lin++) {
    for (col = 0; col < (1 << n); col++)
      fprintf(fout, "%d ", mat[lin][col]);
    fputc('\n', fout);
  }
  fclose(fout);
  return 0;
}
