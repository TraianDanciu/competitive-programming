#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("turism.in");
ofstream fout("turism.out");

const int KMAX = 100;
int v[KMAX + 5];

void remove(int &pos, int &size) {
    for (int i = pos; i < size; i++)
        v[i] = v[i + 1];
    pos--;
	size--;
}

int main() {
    int n, m, k, nr, size = 0, x, cnt = 0, sum = 0;
    fin >> n >> k >> m;
    while (m--) {
		fin >> nr;
        cnt++;
        for (int i = 1; i <= size; i++) {
            v[i]--;
            if (v[i] == 0)
				remove(i, size);
        }
        while (nr--) {
            fin >> x;
            if (size < k) {
				v[++size] = x;
				sum += x;
			}
        }
    }
    while (size) {
        for (int i = 1; i <= size; i++) {
            v[i]--;
            if (v[i] == 0)
				remove(i, size);
        }
        cnt++;
    }
	fout << sum << ' ' << cnt / n + (cnt % n > 0);
    return 0;
}