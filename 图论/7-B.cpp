#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// 使用BFS统计从一个度为0的点到另一个度为0的点的简单路径个数
int countSimplePaths(int n, int m, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);
    vector<int> outDegree(n + 1, 0);
    vector<int> zeroDegreeNodes;

    // 构建有向图，并记录每个节点的入度和出度
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        inDegree[v]++;
        outDegree[u]++;
    }

    // 找出所有入度为0且出度也为0的节点
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0 && outDegree[i] == 0) {
            zeroDegreeNodes.push_back(i);
        }
    }

    // 如果没有这样的节点，直接返回0
    if (zeroDegreeNodes.empty()) {
        return 0;
    }

    int pathCount = 0;

    // 使用BFS查找从一个入度为0且出度为0的节点到另一个入度为0且出度为0的节点的所有路径
    for (int start : zeroDegreeNodes) {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    // 如果到达的邻居节点也是入度为0且出度为0的节点，计数加1
                    if (inDegree[neighbor] == 0 && outDegree[neighbor] == 0) {
                        pathCount = (pathCount + 1) % MOD;
                    }
                }
            }
        }
    }

    return pathCount;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = { u, v };
    }

    cout << countSimplePaths(n, m, edges) << endl;

    return 0;
}
