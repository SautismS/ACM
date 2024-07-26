#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// ʹ��BFSͳ�ƴ�һ����Ϊ0�ĵ㵽��һ����Ϊ0�ĵ�ļ�·������
int countSimplePaths(int n, int m, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);
    vector<int> outDegree(n + 1, 0);
    vector<int> zeroDegreeNodes;

    // ��������ͼ������¼ÿ���ڵ����Ⱥͳ���
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        inDegree[v]++;
        outDegree[u]++;
    }

    // �ҳ��������Ϊ0�ҳ���ҲΪ0�Ľڵ�
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0 && outDegree[i] == 0) {
            zeroDegreeNodes.push_back(i);
        }
    }

    // ���û�������Ľڵ㣬ֱ�ӷ���0
    if (zeroDegreeNodes.empty()) {
        return 0;
    }

    int pathCount = 0;

    // ʹ��BFS���Ҵ�һ�����Ϊ0�ҳ���Ϊ0�Ľڵ㵽��һ�����Ϊ0�ҳ���Ϊ0�Ľڵ������·��
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
                    // ���������ھӽڵ�Ҳ�����Ϊ0�ҳ���Ϊ0�Ľڵ㣬������1
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
