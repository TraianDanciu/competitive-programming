#include <bits/stdc++.h>

using namespace std;

const int MAXK = 1'000; 
const int MAXT = 100;
const int MAXTIMP = 1'000;
const int MAXN = 100'000;

int cnt[MAXK + 1], termin[MAXK + 1];
pair<int, int> timp[MAXN + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, t, lim;
    cin >> n >> k >> t >> lim;
    for(int i = 1; i <= n; i++) {
        cin >> timp[i].first;
        timp[i].second = i;
    }
    sort(timp + 1, timp + n + 1);
    priority_queue<pair<int, int>> finish;
    vector<pair<int, int>> answer;
    int cnt_answer = 0, lst_answer = 0, ptr = 0;
    for(int i = 1; i <= n; i++) {
        while(!finish.empty() && -finish.top().first <= timp[i].first) {
            cnt[finish.top().second]--;
            finish.pop();
        }
        int ok = -1, mintermin = 2e9;
        for(int j = 1; j <= k; j++) {
            if(cnt[j] < lim && max(termin[j], timp[i].first) + t < mintermin) {
                mintermin = max(termin[j], timp[i].first) + t; 
                ok = j;
            }
        }
        if(ok != -1) {
            termin[ok] = max(termin[ok], timp[i].first) + t;
            cnt[ok]++;
            finish.push({-termin[ok], ok});
            cnt_answer++;
            lst_answer = max(lst_answer, termin[ok]);
        }
        answer.push_back({timp[i].second, ok});
    }
    sort(answer.begin(), answer.end());
    cout << cnt_answer << " " << lst_answer << "\n";
    for(auto it : answer) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
