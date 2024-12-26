// Pe primul sunt obligat sa il iau. Pe urmatorul la stanga cu valoare
// mai mare ca el ar fi optim sa il iau, si tot asa.

// Rezultatul final va fi sum(max * (count-1)), unde max va itera prin
// toate maximele partiale, si count va fi la cate pozitii va fi max
// maxim partial. count-1 = cate farfurii va sparge, si facem -1 pentru
// ca nu vom numara si farfuria lui

#include <stdio.h>

const int MAXN = 200'000;

int n, v[MAXN], partial_maximum[MAXN];
long long sum;

void readData() {
  int i;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
}

void computeAnswer() {
  int i, maximum = 0;
  for(i = 0; i < n; i++) {
    sum += maximum;
    if(v[i] > maximum) {
      maximum = v[i];
      partial_maximum[i] = 1;
    }
  }
}

void writeAnswer() {
  int i;
  printf("%lld\n", sum);

  // Mai intai in ordine crescatoare ca sa nu se sparga nimic
  for(i = 0; i < n; i++) {
    if(!partial_maximum[i]) {
      printf("%d ", i + 1);
    }
  }

  // Apoi in ordine descrescatoare ca sa nu sparga primul tot
  for(i = n - 1; i >= 0; i--) {
    if(partial_maximum[i]) {
      printf("%d ", i + 1);
    }
  }

  fputc('\n', stdout);
}

int main() {
  readData();
  computeAnswer();
  writeAnswer();
  return 0;
}
