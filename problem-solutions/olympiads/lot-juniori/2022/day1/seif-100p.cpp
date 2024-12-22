#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int nmax = 500;
int mat[5 + nmax][5 + nmax], total[5 + nmax];
vector<int> chenar[5 + nmax];

int main() {
  ifstream fin("seif.in");
  ofstream fout("seif.out");
  int n;
  fin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      fin >> mat[i][j];
  for (int i = 1; i <= n; i++) {
    int lin = i, col = i;
    while (col < n + 1 - i)
      chenar[i].push_back(mat[lin][col++]);
    while (lin < n + 1 - i)
      chenar[i].push_back(mat[lin++][col]);
    while (col > i)
      chenar[i].push_back(mat[lin][col--]);
    while (lin > i)
      chenar[i].push_back(mat[lin--][col]);
  }
  int t;
  fin >> t;
  while (t--) {
    int pos, cnt;
    char type;
    fin >> pos >> cnt >> type;
    cnt %= chenar[pos].size();
    if (type == 'S')
      cnt = chenar[pos].size() - cnt;
    total[pos] += cnt;
    if (total[pos] >= chenar[pos].size())
      total[pos] -= chenar[pos].size();
  }
  for (int i = 1; i <= n; i++) {
    reverse(chenar[i].begin(), chenar[i].end());
    reverse(chenar[i].begin(), chenar[i].begin() + total[i]);
    reverse(chenar[i].begin() + total[i], chenar[i].end());
    int lin = i, col = i, it = 0;
    while (col < n + 1 - i)
      mat[lin][col++] = chenar[i][it++];
    while (lin < n + 1 - i)
      mat[lin++][col] = chenar[i][it++];
    while (col > i)
      mat[lin][col--] = chenar[i][it++];
    while (lin > i)
      mat[lin--][col] = chenar[i][it++];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      fout << mat[i][j] << ' ';
    fout << '\n';
  }
  return 0;
}
