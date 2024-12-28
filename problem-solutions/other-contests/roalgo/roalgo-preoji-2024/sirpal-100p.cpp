#include <stdio.h>

#define MAXVAL 1000000
#define MAXN 1000000

int prima[MAXVAL + 1], v[MAXN], pozitie[MAXN];

int main() {
  FILE *fin, *fout;
  int n, i, x, max;
  
  fin = fopen("sirpal.in", "r");
  fscanf(fin, "%d", &n);
  for(i = 0; i < n; i++)
    fscanf(fin, "%d", &v[i]);
  fclose(fin);
  
  // resetez valorile
  for(i = 0; i <= MAXVAL; i++)
    prima[i] = -1;
  
  for(i = n - 1; i >= 0; i--) {
    if(prima[v[i]] == -1)
      prima[v[i]] = i;
    
    pozitie[i] = prima[v[i]];
  }
  
  fout = fopen("sirpal.out", "w");
  max = 0;
  for(i = 0; i < n; i++) {
    fputc('0' + (max > i), fout);
    max = pozitie[i] > max ? pozitie[i] : max;
  }
  fputc('\n', fout);
  fclose(fout);
  
  return 0;
}
