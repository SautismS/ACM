#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>>& list, vector<int>& max, vector<bool>& mark) {
    stack<int> s;
    s.push(v);
    int fin = v;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!mark[u]) {
            mark[u] = true;
            if (u > fin) {
                fin = u;
            }
            for (int x : list[u]) {
                if (!mark[x]) {
                    s.push(x);
                }
            }
        }
    }
    max[v] = fin;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> list(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
    }

    vector<int> max(N + 1);
    for (int i = 1; i <= N; ++i) {
        vector<bool> mark(N + 1, false);
        dfs(i, list, max, mark);
    }

    for (int i = 1; i <= N; ++i) {
        cout << max[i] << " ";
    }

    return 0;
}
