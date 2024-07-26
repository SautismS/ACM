#include <bits/stdc++.h>
using namespace std;

// 计算最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// 计算最小公倍数
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int x, y;
    cin >> x >> y;

    vector<pair<int, int>> results;

    // 遍历a1的所有可能值，从x开始，以x为步长
    for (int a1 = x; a1 <= (y / 2); a1 += x) {
        // 确保y是a1的倍数，这样可以确保a2是整数
        if (y % (a1 / x) == 0) {
            int a2 = (y * x) / a1; // 计算对应的a2
            if (gcd(a1, a2) == x && lcm(a1, a2) == y) {
                results.emplace_back(a1, a2);
                if (a1 != a2) { // 确保不重复记录相同的组合
                    results.emplace_back(a2, a1);
                }
            }
        }
    }

    cout << results.size() << endl;
    for (const auto& result : results) {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
