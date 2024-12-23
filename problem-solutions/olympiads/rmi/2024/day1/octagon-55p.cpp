#include <stdio.h>
#include <vector>
#include <algorithm>

const int MOD = 1'000'000'007;
#define int long long

int v[8];

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

// Cati de x si y exista a.i. x <= a, y <= b si y - x = k?
int numWays(int a, int b, int k) {
  return max(0, min(a, b - k) - max(0, -k) + 1);
}

struct Event {
  int poz, num_ways, which;
};
std::vector<Event> events;

int gauss(int n) {
  return 1LL * n * (n + 1) / 2 % MOD;
}

int processEvents() {
    return 0;
}

signed main() {
  int i, answer, num_a, a, b, num_other;
  long long false_cases;

  for(i = 0; i < 8; i++) {
    scanf("%lld", &v[i]);
  }
    
    if(v[1] == 0 && v[3] == 0 && v[5] == 0 && v[7] == 0) {
        answer = 1LL * numWays(v[0], v[4], 0) * numWays(v[2], v[6], 0) % MOD;
    } else {

  answer = 0;
  for(a = -v[0]; a <= v[4]; a++) {
    b = -v[2];
    if((a + b) % 2) {
      b++;
    }
    for(; b <= v[6]; b += 2) {
      num_a = 1LL * numWays(v[0], v[4], a) * numWays(v[2], v[6], b) % MOD;
      num_other = 1LL * numWays(v[5], v[1], (a + b) / 2) *
                              numWays(v[7], v[3], (b - a) / 2) % MOD;
      answer = (answer + 1LL * num_a * num_other) % MOD;
    }
  } }

  // Acum sa scadem cazurile in care maxim doua sunt nenule:
  // Cazul 0. Toate sunt nule => un caz (a = b = 0)
  false_cases = 1;

  // Cazul 1. Doar una e nenula. Daca ans[par] e nenul atunci a este nenul si 
  // b este 0 deci (a + b) / 2 = a / 2 care e nenul contradictie. Atunci poz
  // nenula este impara deci (a + b) / 2 nenul deci a + b nenul deci a nenul
  // sau b nenul => contradictie (analog celelalte cazuri)

  // Cazul 2. Doua sunt nenule.
  // Subcaz 1. Daca doua impare sunt nenule atunci imparul coleg al lui este
  // nenul (altfel a nenul sau b nenul si un par ar deveni nenul). Deci ai 
  // min(v[1], v[5]) + min(v[3], v[7]) variante
  false_cases += min(v[1], v[5]) + min(v[3], v[7]);

  // Subcaz 2. Doua pare sunt nenule
  // Daca doua pare colege sunt nenule => ele sunt egale si avem inca
  // min(v[0], v[4]) + min(v[2], v[6]) variante
  false_cases += min(v[0], v[4]) + min(v[2], v[6]);
  // Daca doua pare necolege sunt nenule atunci a si b sunt nenule si avem
  // a + b = 0 si b - a = 0 deci a = b = 0 => contradictie

  // Subcaz 3. Un par si un impar sunt nenule
  // Daca 0 este nenul => 0 = ans[0] + a => a = -ans[0] si b = 0 deci avem
  // ans[5] != ans[1] si ans[3] != ans[7] => contradictie. Destul de analog
  // se rezolva si celalalte cazuri

  answer -= false_cases % MOD;
  if(answer < 0) {
    answer += MOD;
  }

  printf("%lld\n", answer);
  return 0;
}
