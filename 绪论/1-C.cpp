#include <bits/stdc++.h>
using namespace std;

int main() {
    long T;
    int n;
    cin >> T >> n;

    vector<long long> t(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    long long maxProfit = 0;

    //二进制枚举
    for (int m = 0; m < (1 << n); ++m) {
        long long total = 0;
        long long currentProfit = 0;
        int k = 1;

        for (int i = 0; i < n; ++i) {
            if (m & (1 << i)) {
                total += t[i];
                currentProfit += k * w[i];
                ++k;
            }
        }

        if (total <= T) {
            if (maxProfit < currentProfit) {
                maxProfit = currentProfit;
            }
        }
    }

    cout << maxProfit << endl;
    return 0;
}