#include <iostream>
 
using namespace std;
 
#define MAXN 100000

int probleme[MAXN], penalty[MAXN];
 
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 0; i < p; i++) {
        int x, y, h, m;
    		char ch;
        cin >> x >> y >> h >> ch >> m;
        probleme[x - 1]++;
        penalty[x - 1] += h * 60 + m;
    }
    
    int maxprobleme = 0, minpenalty = 1000000000;
    for(int i = 0; i < n; i++) {
        if(probleme[i] > maxprobleme) { // daca am gasit un concurent cu mai multe probleme
            maxprobleme = probleme[i]; // el devine pe locul 1
            minpenalty = penalty[i];
        } else if(probleme[i] == maxprobleme) { // daca concurentul are la fel de multe probleme ca locul 1
            if(penalty[i] < minpenalty) { // daca are penalty mai putin, el devine locul 1
                minpenalty = penalty[i];
            }
        }
    }
    
    // numarul de probleme al castigatorului este maxprobleme, iar penalty-ul este minpenalty
    for(int i = 0; i < n; i++) {
        if(probleme[i] == maxprobleme && penalty[i] == minpenalty) {
            cout << i + 1 << " "; // daca are aceleasi statistici e pe locul 1
        }
    }
    cout << "\n";
    return 0;
}
