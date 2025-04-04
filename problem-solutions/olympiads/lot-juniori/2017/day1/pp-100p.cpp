#include <stdio.h>

const int MAXN = 100'000;

FILE *fin, *fout;
int task, n, v[MAXN + 2], first_equal[MAXN + 1], last_equal[MAXN + 1];
long long sp[MAXN + 1], sp_len[MAXN + 1], sp_square[MAXN + 1];

void openFiles() {
  fin = fopen("pp.in", "r");
  fout = fopen("pp.out", "w");
}

void readData() {
  int i;
  fscanf(fin, "%d%d", &task, &n);
  for(i = 1; i <= n; i++) {
    fscanf(fin, "%d", &v[i]);
  }
}

void computeNextEqual() {
  int i;
  v[0] = v[n + 1] = -1; // santinele
  for(i = 1; i <= n; i++) {
    if(v[i] == v[i - 1]) {
      first_equal[i] = first_equal[i - 1];
    } else {
      first_equal[i] = i;
    }
  }
  for(i = n; i >= 1; i--) {
    if(v[i] == v[i + 1]) {
      last_equal[i] = last_equal[i + 1];
    } else {
      last_equal[i] = i;
    } 
  }
}

long long square(int x) {
  return 1LL * x * x;
}

void buildPrefixSums() {
  int i;
  for(i = 1; i <= n; i++) {
    sp[i] = sp[i - 1] + v[i];
    if(v[i] != v[i - 1]) {
      sp_len[i] = last_equal[i] - i + 1;
      sp_square[i] = square(last_equal[i] - i + 1);
    }
    sp_len[i] += sp_len[i - 1];
    sp_square[i] += sp_square[i - 1];
  }
}

void answerQueries() {
  int q, st, dr, st2, dr2;
  long long sum, sum_square;
  fscanf(fin, "%d", &q);
  while(q--) {
    fscanf(fin, "%d%d", &st, &dr);
    if(task == 1) {
      fprintf(fout, "%lld\n", sp[dr] - sp[st - 1]);
    } else {
      st2 = first_equal[st];
      dr2 = last_equal[dr];

      sum = sp_len[dr2] - sp_len[st2 - 1];
      sum -= st - st2;
      sum -= dr2 - dr;

      sum_square = sp_square[dr2] - sp_square[st2 - 1];
      sum_square -= square(last_equal[st] - st2 + 1) - square(last_equal[st] - st + 1);
      sum_square -= square(dr2 - first_equal[dr] + 1) - square(dr - first_equal[dr] + 1);

      fprintf(fout, "%lld\n", ((dr - st + 1) * sum - sum_square) / 2);
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
  computeNextEqual();
  buildPrefixSums();
  answerQueries();
  closeFiles();
  return 0;
}
