#include <stdio.h>
#include <ctype.h>
#include <algorithm>

const int MAXDIGITS = 201;

FILE *fin, *fout;
char a[MAXDIGITS], b[MAXDIGITS], n[MAXDIGITS], c[MAXDIGITS];
int a_digits, b_digits, c_digits, n_digits, steps;

void openFiles() {
  fin = fopen("euclid.in", "r");
  fout = fopen("euclid.out", "w");
}

void readData() {
  int i;
  while(isdigit(n[n_digits] = fgetc(fin))) {
    n[n_digits++] -= '0';
  }
  for(i = 0; i < n_digits / 2; i++) {
    std::swap(n[i], n[n_digits - 1 - i]);
  }
}

void getNewNumber() {
  int t = 0;
  c_digits = 0;
  while(t > 0 || c_digits < a_digits || c_digits < b_digits) {
    t += a[c_digits] + b[c_digits];
    c[c_digits++] = t % 10;
    t /= 10;
  }
}

void copyNumber(char a[MAXDIGITS], int &a_digits, char b[MAXDIGITS], int &b_digits) {
  int i;
  a_digits = b_digits;
  for(i = 0; i < b_digits; i++) {
    a[i] = b[i];
  }
}

int compareLimit() {
  int i;

  if(n_digits > c_digits) {
    return 1;
  }
  if(n_digits < c_digits) {
    return 0;
  }

  i = n_digits - 1;
  while(i >= 0 && n[i] == c[i]) {
    i--;
  }

  return i < 0 || n[i] > c[i];
}

void computeAnswer() {
  steps = 1;
  a[0] = a_digits = b[0] = b_digits = 1;
  while(getNewNumber(), compareLimit()) {
    steps++;
    copyNumber(a, a_digits, b, b_digits);
    copyNumber(b, b_digits, c, c_digits);
  }
}

void writeAnswer() {
  int i;
  fprintf(fout, "%d\n", steps);
  for(i = a_digits - 1; i >= 0; i--) {
    fputc('0' + a[i], fout);
  }
  fputc('\n', fout);
  for(i = b_digits - 1; i >= 0; i--) {
    fputc('0' + b[i], fout);
  }
  fputc('\n', fout);
}

void closeFiles() {
  fclose(fin);
  fclose(fout);
}

int main() {
  openFiles();
  readData();
  computeAnswer();
  writeAnswer();
  closeFiles();
  return 0;
}
