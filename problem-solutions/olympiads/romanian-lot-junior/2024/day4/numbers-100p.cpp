// Vom roti maxim 14 numere (unul pentru fiecare numar de cifre cu care rotim). 
// Pentru fiecare numar de cifre, vom avea nevoie de 14 candidati (pentru cazul
// in care primii 13 se duc la toate celelalte cifre). Asa ca, in total, vom
// avea nevoie sa procesam maxim 14*14=196 numere. Asa ca vom aplica solutia de
// 80 de puncte pe cele mai bune 14 numere pt fiecare nr de cifre, iar restul
// vor fi adunate fara a fi rotite. Dupa cateva calcule, obtinem complexitatea
// O(CF * n log n + 2^CF * CF^3)

#include <stdio.h>
#include <vector>
#include <algorithm>

const int MAXN = 10'000;
const int MAXCF = 15;
const int NUM_SELECTED = MAXCF - 1;
const int MAXROT = MAXCF - 1;
const int NUM_LINES = 2;

FILE *fin, *fout;
int n, num_chosen;
long long v[MAXN], rotate[MAXN][MAXCF], answer, dp[NUM_LINES][1 << MAXROT];
std::vector<int> rotations[MAXCF];
int chosen[MAXN];

void openFiles() {
  fin = fopen("numbers.in", "r");
  fout = fopen("numbers.out", "w");
}

void readArray() {
  int i;
  fscanf(fin, "%d", &n);
  for(i = 0; i < n; i++) {
    fscanf(fin, "%lld", &v[i]);
  }
}

void computeRotations() {
  int i, exp10, j;
  long long pleft, pright;
  for(i = 0; i < n; i++) {
    pleft = 1;
    exp10 = 0;
    while(pleft <= v[i]) {
      pleft *= 10;
      exp10++;
    }

    pright = 1;
    for(j = 0; j < exp10; j++) {
      rotate[i][j] = (v[i] % pleft) * pright + v[i] / pleft;
      pleft /= 10;
      pright *= 10;

      rotations[j].push_back(i);
    }
  }
}

int min(int a, int b) {
  return a < b ? a : b;
}

void selectBestNumbers() {
  int cf, select, i;
  for(cf = 1; cf < MAXCF; cf++) {
    std::sort(rotations[cf].begin(), rotations[cf].end(), [cf](int a, int b) {
      // Sortam dupa cat adauga la suma, pentru ca, de exemplu, numerele care
      // sunt in cea mai buna versiune a lor daca nu le rotim nu pot fi alese
      return rotate[a][cf] - rotate[a][0] > rotate[b][cf] - rotate[b][0];
    });
  
    select = min((int)rotations[cf].size(), NUM_SELECTED);
    for(i = 0; i < select; i++) {
      chosen[rotations[cf][i]] = 1;
    }
  }

  num_chosen = 0;
  for(i = 0; i < n; i++) {
    if(chosen[i]) {
      chosen[num_chosen++] = i;
    } else {
      answer += v[i]; // Adaugam celelalte numere
    }
  }
}

long long max(long long a, long long b) {
  return a > b ? a : b;
}

void computeDp() {
  int i, mask, bit;
  for(i = 0; i < num_chosen; i++) {
    for(mask = 0; mask < (1 << MAXROT); mask++) {
      dp[i % 2][mask] = dp[1 - i % 2][mask] + rotate[chosen[i]][0];
      for(bit = 0; bit < MAXROT; bit++) {
        if(mask & (1 << bit)) {
          dp[i % 2][mask] = max(dp[i % 2][mask],
              dp[1 - i % 2][mask ^ (1 << bit)] + rotate[chosen[i]][bit + 1]);
        }
      }
    }
  }
}

void writeAnswer() {
  int mask;
  long long maxim = 0;
  for(mask = 0; mask < (1 << MAXROT); mask++) {
    maxim = max(maxim, dp[1 - num_chosen % 2][mask]);
  }
  fprintf(fout, "%lld\n", answer + maxim);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readArray();
  computeRotations();
  selectBestNumbers();
  computeDp();
  writeAnswer();
  closeFiles();
  return 0;
}
