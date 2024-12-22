// n=1000 deci putem face ceva dp in n^2 deci putem face range dp. Daca am defini
// dp[st][dr] ca fiind numarul de trasee care formeaza intervalul [st, dr] nu ar
// fi de ajuns, pentru ca noi putem sa plecam din st si sa ajungem in dr sau
// invers. Atunci fie dp[st][dr][STANGA] = numarul de trasee in care plecam din 
// st si ajungem in dr trecand prin tot intervalul [st, dr]. Analog, definim si
// dp[st][dr][DREAPTA] = numarul de trasee in care plecam din dr si ajungem in st
// si trecem prin tot intervalul [st, dr]

#include <stdio.h>

const int MAXN = 1'000;
const int STANGA = 0;
const int DREAPTA = 1;
const int NUM_STARI = 2;
const int MOD = 1'000'000'007;

FILE *fin, *fout;
char reach[MAXN][MAXN]; // Daca reach[i][j] = 0 atunci putem face o diagonala
                        // de la i la j (daca reach[i][j] = 1 atunci nu putem)
int n, dp[MAXN][MAXN][NUM_STARI];

void openFiles() {
  fin = fopen("trasee.in", "r");
  fout = fopen("trasee.out", "w");
}

void readRestrictions() {
  int i, m, a, b;
  fscanf(fin, "%d%d", &n, &m);
  for(i = 0; i < m; i++) {
    fscanf(fin, "%d%d", &a, &b);
    reach[a - 1][b - 1] = reach[b - 1][a - 1] = 1;
  }
}

// Add b to a (modulo MOD)
void add(int &a, int b) {
  a += b;
  if(a >= MOD) {
    a -= MOD;
  }
}

void computeDp() {
  int st, dr;
  for(st = n - 1; st >= 0; st--) {
    dp[st][st][STANGA] = 1;
    for(dr = st + 1; dr < n; dr++) {
      if(reach[st + 1][st] == 0) { // Din st + 1 mergem in st
        add(dp[st][dr][STANGA], dp[st + 1][dr][STANGA]);
      }
      if(reach[dr][st] == 0) { // Din dr mergem in st
        add(dp[st][dr][STANGA], dp[st + 1][dr][DREAPTA]);
      }
      if(reach[st][dr] == 0) { // Din st mergem in dr
        add(dp[st][dr][DREAPTA], dp[st][dr - 1][STANGA]);
      }
      if(reach[dr - 1][dr] == 0) { // Din dr - 1 mergem in dr
        add(dp[st][dr][DREAPTA], dp[st][dr - 1][DREAPTA]);
      }
    }
  }
}

void writeAnswer() {
  fprintf(fout, "%d\n", dp[0][n - 1][STANGA]);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);  
}

int main() {
  openFiles();
  readRestrictions();
  computeDp();
  writeAnswer();
  closeFiles();
  return 0;
}
