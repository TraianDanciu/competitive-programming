#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back

using namespace std;

int to_int(string s) {
    int ans = 0;
    for (char ch : s)
        ans = ans * 10 + (ch - '0');
    return ans;
}
ll to_ll(string s) {
    ll ans = 0;
    for (char ch : s)
        ans = ans * 10 + (ch - '0');
    return ans;
}

int values[30];
vector<int> solutions;
vector<pair<string, string>> nodes;
vector<string> expressions;
vector<vector<int>> g;

void dfs(int node = 1, int father = 0) {
    if (nodes[node].first == "()")
        for (auto son : g[node]) {
            if (son == father)
                continue;
            dfs(son, node);
            expressions[node] = "(" + expressions[son] + ")";
            solutions[node] = solutions[son];
        }
    else if (nodes[node].first == "") {
        if (isalpha(nodes[node].second[0]))
            solutions[node] = values[nodes[node].second[0] - 'a' + 1];
        else
            solutions[node] = to_int(nodes[node].second);
        expressions[node] = nodes[node].second;
    }
    else {
        int counter = 0;
        for (auto son : g[node]) {
            if (son == father)
                continue;
            dfs(son, node);
            if (counter == 0)
                expressions[node] += expressions[son], solutions[node] = solutions[son];
            else {
                expressions[node] += nodes[node].first + expressions[son];
                switch (nodes[node].first[0]) {
                    case '+': {
                        solutions[node] += solutions[son];
                        break;
                    }
                    
                    case '-': {
                        solutions[node] -= solutions[son];
                        break;
                    }
                    
                    case '*': {
                        solutions[node] *= solutions[son];
                        break;
                    }
                    
                    case '/': {
                        solutions[node] /= solutions[son];
                        break;
                    }
                }
            }
            counter++;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    for (int i = 1; i <= 26; i++)
        cin >> values[i];
    int n;
    cin >> n;
    nodes.resize(n + 1);
    g.resize(n + 1);
    solutions.resize(n + 1);
    expressions.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].first;
        if (isdigit(nodes[i].first[0]) || isalpha(nodes[i].first[0]))
            nodes[i].second = nodes[i].first, nodes[i].first = "";
        else {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int u;
                cin >> u;
                g[i].pb(u);
                g[u].pb(i);
            }
        }
    }
    dfs();
    cout << expressions[1] << '\n' << solutions[1];
    return 0;
}
