#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int DP(int n, vector<int>& steps) {
    vector<long long> dp(n + 1, 0);

    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int step : steps) {
            if (i - step > 0) {
                dp[i] = (dp[i] + dp[i - step]) % MOD;
            }
        }
    }
    return dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> steps(k);
    for (int i = 0; i < k; ++i) {
        cin >> steps[i];
    }

    cout << DP(n, steps) << endl;

    return 0;
}
