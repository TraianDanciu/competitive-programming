#include <stdio.h>
#include <vector>
#include <algorithm>

const int MAXN = 100;
const int INFINIT = 1000000000;

char mat[MAXN][MAXN];
int cnt, n;

// mut de sus in jos
// daca cnt % 2 == 1 atunci ramane una sus
int solve() {
  int up = 0;
  for(int l = 0; l < n / 2; l++) {
    for(int c = 0; c < n; c++) {
      up += mat[l][c];
    }
  }
  int down = 0;
  for(int l = n / 2; l < n; l++) {
    for(int c = 0; c < n; c++) {
      down += mat[l][c];
    }
  }
  
  if(up < down) {
    return INFINIT;
  }
  
  std::vector<int> candidates;
  for(int c = 0; c < n; c++) {
    int ptr = n / 2;
    for(int i = n / 2 - 1; i >= 0; i--) {
      if(mat[i][c] == 0) {
        continue;
      }
      while(ptr < n && mat[ptr][c] == 1) {
        ptr++;
      }
      if(ptr == n) {
        break;
      }
      candidates.push_back(ptr - i);
      ptr++;
    }
  }
  
  std::sort(candidates.begin(), candidates.end());
  int answer = 0, op = cnt / 2 - down;
  // up + down = cnt si up >= down deci op >= 0
  if((int)candidates.size() < op) { // nu stiu sigur daca e necesar dar better safe than sorry
    return 1e9;                     // + nu cred ca stau sa demonstrez de ce n-ar fi necesar
  }
  for(int i = 0; i < op; i++) {
    answer += candidates[i];
  }
  
  return answer;
}

int main() {
  FILE *fin = fopen("cmin.in", "r");
  fscanf(fin, "%d", &n);
  for(int l = 0; l < n; l++) {
    for(int c = 0; c < n; c++) {
      fscanf(fin, "%hhd", &mat[l][c]);
    }
  }
  fclose(fin);
  
  for(int l = 0; l < n; l++) {
    for(int c = 0; c < n; c++) {
      cnt += mat[l][c];
    }
  }
  
  int answer = solve();
  // rastorn matricea
  for(int c = 0; c < n; c++) {
    for(int st = 0, dr = n - 1; st < dr; st++, dr--) {
      std::swap(mat[st][c], mat[dr][c]);
    }
  }
  answer = std::min(answer, solve());
  
  FILE *fout = fopen("cmin.out", "w");
  fprintf(fout, "%d\n", answer);
  fclose(fout);
  return 0;
}