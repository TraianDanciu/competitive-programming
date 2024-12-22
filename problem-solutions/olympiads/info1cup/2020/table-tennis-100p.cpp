// Sortez de la inceput sirul si un sir "balanced" va fi un sir pentru
// care v[1] + v[n] = v[2] + v[n - 1] = .. = v[n/2] + v[n/2+1] = S

// Fixez primul element neselectat si ultimul element neselectat, si
// pot sa aflu S. Si de aici verific intr-un fel de interclasare.

// Complexitate: O(n*k^2), cred ca o sa ia cam 87p, si, dupa calculele
// mele, o sa trebuiasca sa optimizez la O(n*k)

// Optimizare (care nu stiu daca o sa fie indeajuns pentru 100p): Cand
// gasim o solutie, oprim imediat cautarea.

// Optimizare 2: In loc sa trec prin toate perechile si sa scot la
// final ce e prea mult, doar o sa ma opresc din a cauta perechi cand
// ajung la k.

// Optimizare 3: Pun perechile in raspuns in timp ce le procesez. Cu
// astea doua optimizari scap de foarte multe iteratii inutile

#include <stdio.h>
#include <algorithm>

const int MAXN = 150'000;
const int MAXK = 400;

int v[MAXN + MAXK], n, k, answer[MAXN];

void readData() {
  int i;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n + k; i++) {
    scanf("%d", &v[i]);
  }
}

void sortArray() {
  std::sort(v, v + n + k);
}

int getPairs(int st, int dr, int left_over) {
  int sum = v[st] + v[dr], ptr = 0;
  while(st < dr && left_over <= k) {
    if(v[st] + v[dr] < sum) {
      st++; // st nu va mai putea fi in nicio pereche (e prea mic)
      left_over++;
    } else if(v[st] + v[dr] > sum) {
      dr--; // dr nu va mai putea fi in nicio pereche (e prea mare)
      left_over++;
    } else {
      if(ptr < n - 1 - ptr) {
        answer[ptr] = v[st];
        answer[n - 1 - ptr] = v[dr];
        ptr++;
      }
      st++;
      dr--;
    }
  }
  return left_over <= k;
}

void findAnswer() {
  int first_value, last_value, left_over, found_sol;
  first_value = found_sol = 0;
  while(first_value <= k && !found_sol) {
    last_value = n - 1;
    while(last_value < n + k && !found_sol) {
      if(first_value <= last_value) {
        left_over = first_value + n + k - last_value - 1;
        if(getPairs(first_value, last_value, left_over)) {
          found_sol = 1;
        }
      }
      last_value++;
    }
    first_value++;
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
