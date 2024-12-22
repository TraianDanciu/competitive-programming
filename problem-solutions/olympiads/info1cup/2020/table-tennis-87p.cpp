// Sortez de la inceput sirul si un sir "balanced" va fi un sir pentru
// care v[1] + v[n] = v[2] + v[n - 1] = .. = v[n/2] + v[n/2+1] = S

// Fixez primul element neselectat si ultimul element neselectat, si
// pot sa aflu S. Si de aici verific intr-un fel de interclasare.

// Complexitate: O(n*k^2), cred ca o sa ia cam 87p, si, dupa calculele
// mele, o sa trebuiasca sa optimizez la O(n*k)

#include <stdio.h>
#include <algorithm>

const int MAXN = 150'000;
const int MAXK = 400;

int v[MAXN + MAXK], n, k, answer[MAXN];
char used_value[MAXN + MAXK];

void readData() {
  int i;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n + k; i++) {
    scanf("%d", &v[i]);
  }
}

void sortArray() {
  std::sort(v, v + n);
}

int getPairs(int st, int dr, int &left_over) {
  int sum = v[st] + v[dr];
  while(st < dr) {
    if(v[st] + v[dr] < sum) {
      st++; // st nu va mai putea fi in nicio pereche (e prea mic)
      left_over++;
    } else if(v[st] + v[dr] > sum) {
      dr--; // dr nu va mai putea fi in nicio pereche (e prea mare)
      left_over++;
    } else {
      used_value[st] = used_value[dr] = 1;
      st++;
      dr--;
    }
  }
  return st;
}

void removePairs(int st, int num_pairs) {
  int dr = st + 1;
  while(num_pairs > 0) {
    if(used_value[st] && used_value[dr]) {
      used_value[st] = used_value[dr] = 0;
      num_pairs--;
    } else {
      if(!used_value[st]) {
        st--;
      }
      if(!used_value[dr]) {
        dr++;
      }
    }
  }
}

void findAnswer() {
  int first_value, last_value, left_over, ptr, i, stopped_value;
  for(first_value = 0; first_value <= k; first_value++) {
    for(last_value = n - 1; last_value < n + k; last_value++) {
      if(first_value <= last_value) {
        left_over = first_value + n + k - last_value - 1;
        stopped_value = getPairs(first_value, last_value, left_over);
        if(left_over <= k && (k - left_over) % 2 == 0) {
          removePairs(stopped_value, (k - left_over) / 2);
          ptr = 0;
          for(i = 0; i < n + k; i++) {
            if(used_value[i]) {
              answer[ptr++] = v[i];
            }
          }
        }
        for(i = 0; i < n + k; i++) {
          used_value[i] = 0;
        }
      }
    }
  }
}

void writeAnswer() {
  int i;
  for(i = 0; i < n; i++) {
    printf("%d ", answer[i]);
  }
  fputc('\n', stdout);
}

int main() {
  readData();
  sortArray();
  findAnswer();
  writeAnswer();
  return 0;
}
