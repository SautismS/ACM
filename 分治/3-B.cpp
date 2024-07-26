#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL INF = LLONG_MAX / 2;

//动态规划
LL DP(vector<vector<int>>& S, int n) {
    vector<vector<LL>> dp(1 << n, vector<LL>(n, INF));
    dp[1][0] = 0;

    for (int m = 1; m < (1 << n); m++) {
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if (!(m & (1 << j))) {
                        if (dp[m][i] + S[i][j] < dp[m | (1 << j)][j]) {
                            dp[m | (1 << j)][j] = dp[m][i] + S[i][j];
                        }
                    }
                }
            }
        }
    }

    LL result = INF;
    for (int i = 1; i < n; i++) {
        if (dp[(1 << n) - 1][i] + S[i][0] < result) {
            result = dp[(1 << n) - 1][i] + S[i][0];
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> S(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }

    LL result = DP(S, n);
    cout << result << endl;

    return 0;
}

//深度搜索（未使用）
int r = INT_MAX;
void DFS(vector<vector<int>>& S, vector<bool>& V, int cur, int n, int count, int s) {
    if (count == n && S[cur][0] > 0) {
        if (r > s + S[cur][0]) {
            r = s + S[cur][0];
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!V[i] && S[cur][i] > 0) {
            V[i] = true;
            DFS(S, V, i, n, count + 1, s + S[cur][i]);
            V[i] = false;
        }
    }
}
