#include <iostream>

using namespace std;

#define MAXN 39

int v[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int n, ch;
	n = 0;
	while(isdigit(ch = cin.get())) {
		n = n * 10 + ch - '0';	
	}
    for(int i = 0; i < n; i++) {
        // cate stele sunt pe rand
        while(cin.get() == '*') {
            v[i]++;
        }
    }
    
    // daca v[0] e numar fibonacci
    int a = 0, b = 1, c;
    while(a < v[0]) {
        c = a + b;
        a = b;
        b = c;
    }
    
    // testam si daca v[1] e urmatorul numar fibonacci
    if((v[0] == 1 && v[1] == 2) || (v[0] == a && v[1] == b)) {
        int i = 2; // testam numerele dupa regula de generare
        while(i < n && v[i] == v[i - 1] + v[i - 2]) {
            i++;
        }
        
        if(i == n) {
            cout << "DA\n";
        } else {
            cout << "NU\n";
        }
    } else {
        cout << "NU\n";
    }
    return 0;
}
