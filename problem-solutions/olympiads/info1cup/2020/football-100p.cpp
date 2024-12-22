// Tratam cazul n = 1 astfel. Fie x = v[1]

// Daca x este impar, vom lua 1. El nu are ce altceva sa ia si noi vom castiga.

// Daca x este par, vom considera cazul cand x%4 = 2. Noi vom lua 2. Acum, el
// daca ia 1, ne va lasa noua un nr impar si castigam. Asa ca el va lua 2, si
// va merge tot asa pana cand noi o sa fim ultimii pt ca x/2 e impar

// Daca x%4 = 0, vom considera cazul cand x%8 = 4. Si este analog ca mai sus
// Asa vom face pana cand puterea devine mai mare decat k.

// Deducem ca noi castigam daca x are vreun bit mai mic strict decat 2^p, unde p
// este cel mai mare numar care respecta x < 2^p. Cu alte cuvinte, vrem ca
// x % (2^p) sa fie diferit de 0.

// Acum sa ne intoarcem la cazul general. Vom face v[i] %= 2^p, iar din nim asta
// inseamna ca vrem ca xorul sa fie diferit de 0 ca sa castigam (observam ca se
// aplica si la cazul cand n = 1.

#include <stdio.h>

int main() {
  int t, n, k, i, xr, val, p;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &k);
    p = 1;
    while(p <= k) {
      p <<= 1;
    }

    xr = 0;
    for(i = 0; i < n; i++) {
      scanf("%d", &val);
      val &= p - 1;
      xr ^= val;
    }

    printf("%d", xr > 0);
  }
  fputc('\n', stdout);
  return 0;
}
