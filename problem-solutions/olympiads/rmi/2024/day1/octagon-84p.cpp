#include <stdio.h>
#include <vector>
#include <algorithm>

const int MOD = 1'000'000'007;
const int INV2 = (MOD + 1) / 2;
const int MAXN = 200'000;

int v[8], power_sum[4][MAXN + 1];

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

int gauss(int n) {
    return 1LL * n * (n + 1) / 2 % MOD;
}

int getMod2(int n) {
    int rest = n % 2;
    if(rest < 0) {
        rest += 2;
    }
    return rest;
}

// Cate numere din intervalul [st, dr] dau restul rest modulo 2
int numRest(int rest, int st, int dr) {
    // scriem toate numerele ca 2 * k + rest
    if(getMod2(st) != rest) {
        st++;
    }
    st = (st - rest) / 2;
    if(getMod2(dr) != rest) {
        dr--;
    }
    dr = (dr - rest) / 2;
    if(st > dr) {
        return 0;
    }
    return dr - st + 1;
}

void multCoef(int coef_base[4], int coef_mult[2]) {
    int new_coef[5] = {0, 0, 0, 0, 0};
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            new_coef[i + j] = (new_coef[i + j] + 1LL * coef_base[i] * coef_mult[j]) % MOD;
        }
        coef_base[i] = new_coef[i];
    }
}

int rangePowerSum(int st, int dr, int k) {
    long long answer = 0;
    int sign = 1 - 2 * (k % 2);
    if(k == 0) {
        return numRest(getMod2(st), st, dr);
    }
    if(st < 0) {
        answer += sign * power_sum[k][-st];
    } else {
        if(st >= 2) {
            answer -= power_sum[k][st - 2];
        }
    }
    if(dr > 0) {
        answer += power_sum[k][dr];
    } else {
        if(dr <= -2) {
            answer -= sign * power_sum[k][-dr - 2];
        }
    }
    answer %= MOD;
    if(answer < 0) {
        answer += MOD;
    }
    return answer;
}

signed main() {
    int i, answer, a, mask, brange_left, brange_right, b, maxim = 0;
    long long false_cases;

    maxim = 0;
    for(i = 0; i < 8; i++) {
        scanf("%d", &v[i]);
        maxim = max(maxim, v[i]);
    }
    
    
    if(v[1] == 0 && v[3] == 0 && v[5] == 0 && v[7] == 0) {
        answer = 1LL * numWays(v[0], v[4], 0) * numWays(v[2], v[6], 0) % MOD;
    } else {
        for(i = 1; i <= maxim; i++) {
            power_sum[0][i] = 1;
            for(int j = 1; j <= 3; j++) {
                power_sum[j][i] = 1LL * power_sum[j - 1][i] * i % MOD;
            }
            if(i >= 2) {
                for(int j = 0; j <= 3; j++) {
                    power_sum[j][i] += power_sum[j][i - 2];
                    if(power_sum[j][i] >= MOD) {
                        power_sum[j][i] -= MOD;
                    }
                }
            }
        }
        
        answer = 0;
        for(a = -v[0]; a <= v[4]; a++) {
            
            // Pentru fiecare numWays o sa fixez o masca cu doi biti inseamnand o
            // masca cu doua conditii: k >= 0 sau nu si b - k < a sau nu
            for(mask = 0; mask < 64; mask++) {
                // Mai intai determin intervalul in care se afla b si apoi mai vedem
                brange_left = -v[2];
                brange_right = v[6];
                
                int total_coef[4] = {numWays(v[0], v[4], a), 0, 0, 0};
                int coef_now[2] = {1, 0};
                
                // Conditiile pentru numWays(v[2], v[6], b)
                if(mask & 1) { // b >= 0
                    brange_left = max(brange_left, 0);
                } else { // b < 0
                    brange_right = min(brange_right, -1);
                    
                    coef_now[1]++;
                    if(coef_now[1] >= MOD) {
                        coef_now[1] -= MOD;
                    }
                }
                if(mask & 2) { // v[6] - b < v[2]
                    brange_left = max(brange_left, v[6] - v[2] + 1);
                    if(mask & 1) { // v[6] - b + 1 >= 0
                        brange_right = min(brange_right, v[6] + 1);
                    }
                    
                    coef_now[0] += v[6];
                    if(coef_now[0] >= MOD) {
                        coef_now[0] -= MOD;
                    }
                    coef_now[1]--;
                    if(coef_now[1] < 0) {
                        coef_now[1] += MOD;
                    }
                } else { // v[2] <= v[6] - b
                    brange_right = min(brange_right, v[6] - v[2]);
                    if(!(mask & 1)) { // v[2] + b + 1 >= 0
                        brange_left = max(brange_left, -v[2] - 1);
                    }
                    
                    coef_now[0] += v[2];
                    if(coef_now[0] >= MOD) {
                        coef_now[0] -= MOD;
                    }
                }
                multCoef(total_coef, coef_now);
                coef_now[0] = 1;
                coef_now[1] = 0;
                
                // Conditiile pentru numWays(v[5], v[1], (a + b) / 2)
                if(mask & 4) { // (a + b) / 2 >= 0
                    brange_left = max(brange_left, -a);
                } else { // (a + b) / 2 < 0
                    brange_right = min(brange_right, -a - 1);
                    
                    coef_now[0] = (coef_now[0] + 1LL * INV2 * a) % MOD;
                    if(coef_now[0] < 0) {
                        coef_now[0] += MOD;
                    }
                    coef_now[1] += INV2;
                    if(coef_now[1] >= MOD) {
                        coef_now[1] -= MOD;
                    }
                }
                if(mask & 8) { // v[1] - (a + b) / 2 < v[5]
                    brange_left = max(brange_left, 2 * (v[1] - v[5]) - a + 1);
                    if(mask & 4) { // v[1] - (a + b) / 2 + 1 >= 0
                        brange_right = min(brange_right, 2 * v[1] - a + 2);
                    }
                    
                    coef_now[0] += v[1];
                    if(coef_now[0] >= MOD) {
                        coef_now[0] -= MOD;
                    }
                    coef_now[0] = (coef_now[0] - 1LL * INV2 * a) % MOD;
                    if(coef_now[0] < 0) {
                        coef_now[0] += MOD;
                    }
                    coef_now[1] -= INV2;
                    if(coef_now[1] < 0) {
                        coef_now[1] += MOD;
                    }
                } else { // v[5] <= v[1] - (a + b) / 2
                    brange_right = min(brange_right, 2 * (v[1] - v[5]) - a);
                    if(!(mask & 4)) { // v[5] + (a + b) / 2 + 1 >= 0
                        brange_left = max(brange_left, -2 * v[5] - 2 - a);
                    }
                    
                    coef_now[0] += v[5];
                    if(coef_now[0] >= MOD) {
                        coef_now[0] -= MOD;
                    }
                }
                multCoef(total_coef, coef_now);
                coef_now[0] = 1;
                coef_now[1] = 0;

                // Conditiile pentru numWays(v[7], v[3], (b - a) / 2)
                if(mask & 16) { // (b - a) / 2 >= 0
                    brange_left = max(brange_left, a);
                } else { // (b - a) / 2 < 0
                    brange_right = min(brange_right, a - 1);
                    
                    coef_now[0] = (coef_now[0] - 1LL * a * INV2) % MOD;
                    if(coef_now[0] < 0) {
                        coef_now[0] += MOD;
                    }
                    coef_now[1] += INV2;
                    if(coef_now[1] >= MOD) {
                        coef_now[1] -= MOD;
                    }
                }
                if(mask & 32) { // v[3] - (b - a) / 2 < v[7]
                    brange_left = max(brange_left, 2 * (v[3] - v[7]) + a + 1);
                    if(mask & 16) { // v[3] - (b - a) / 2 + 1 >= 0
                        brange_right = min(brange_right, 2 * v[3] + a + 2);
                    }
                    
                    coef_now[0] += v[3];
                    if(coef_now[0] >= MOD) {
                        coef_now[0] -= MOD;
                    }
                    coef_now[0] = (coef_now[0] + 1LL * a * INV2) % MOD;
                    if(coef_now[0] < 0) {
                        coef_now[0] += MOD;
                    }
                    coef_now[1] -= INV2;
                    if(coef_now[1] < 0) {
                        coef_now[1] += MOD;
                    }
                } else { // v[7] <= v[3] - (b - a) / 2
                    brange_right = min(brange_right, 2 * (v[3] - v[7]) + a);
                    if(!(mask & 16)) { // v[7] + (b - a) / 2 + 1 >= 0
                        brange_left = max(brange_left, a - 2 * v[7] - 2);
                    }
                    
                    coef_now[0] += v[7];
                    if(coef_now[0] >= MOD) {
                        coef_now[0] -= MOD;
                    }
                }
                multCoef(total_coef, coef_now);

                if(getMod2(brange_left) != getMod2(a)) {
                    brange_left++;
                }
                if(getMod2(brange_right) != getMod2(a)) {
                    brange_right--;
                }

                // b nu poate sa ia nicio valoare
                if(brange_left > brange_right) {
                    continue;
                }
                
                for(i = 0; i < 4; i++) {
                    int ipower_sum = rangePowerSum(brange_left, brange_right, i);
                    answer = (answer + 1LL * ipower_sum * total_coef[i]) % MOD;
                }
            }

        }
    }

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

    printf("%d\n", answer);
    return 0;
}
