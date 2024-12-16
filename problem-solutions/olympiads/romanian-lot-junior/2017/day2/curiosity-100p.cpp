#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Punct {
  int tip, val;
};

int main() {
  ifstream fin("curiosity.in");
  ofstream fout("curiosity.out");
  int s, f, c, n;
  fin >> s >> f >> c >> n;
  vector<Punct> pct;
  pct.push_back(Punct{.tip = 3, .val = s}); // ca sa pot reincarca acolo
  for (int i = 1; i <= n; i++) {
    int t, x;
    fin >> t >> x;
    if (s <= x && x <= f)
      pct.push_back(Punct{.tip = t, .val = x});
  }
  pct.push_back(Punct{.tip = 3, .val = f});
  int baterie = 0, incarc1 = 0, incarc2 = 0;
  for (int i = 0; i < pct.size() - 1; i++)
    if (pct[i].tip == 3) {
      // pot sa reincarc linistit
      baterie = c;
      int gata = n + 2, adaug = 0;
      for (int j = i + 1; j < pct.size(); j++) {
        baterie -= pct[j].val - pct[j - 1].val;
        if (baterie < 0) {
          fout << "-1\n";
          return 0;
        }
        if (pct[j].tip == 3) { // tratez cazul asta mai incolo
          gata = j;
          break;
        }
        if (pct[j].tip == 2) // iarasi incarc linistit
          baterie = c;
        else if (pct[j + 1].val - pct[j].val > baterie) {
          if (pct[j + 1].val - pct[j].val > c) {
            fout << "-1\n";
            return 0;
          }
          adaug += pct[j + 1].val - pct[j].val - baterie;
          baterie = pct[j + 1].val - pct[j].val;
        }
      }
      incarc1 += adaug;
      if (pct[gata].val - pct[i].val > adaug + c)
        incarc2 += pct[gata].val - pct[i].val - adaug - c;
      i = gata - 1;
    }
  fout << incarc1 << ' ' << incarc2 << '\n';
  return 0;
}
