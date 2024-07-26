#include <bits/stdc++.h>
using namespace std;

inline int f(int i, int j, int k) {
    return 2 * i * i + 2 * j * j + k * k + i * j + 2 * i * k + 2 * j * k;
}

int process(int n, int m, int p, int x) {
    int count = 0;
    int sqrt_x = sqrt(x) + 1; // 计算 sqrt(x) 并加1，用于减少循环范围

    for (int i = 1; i <= n && i <= sqrt_x; ++i) {
        for (int j = 1; j <= m && j <= sqrt_x; ++j) {
            int left = 1;
            int right = min(sqrt_x, p); // 将 right 限制为 sqrt(x) 和 p 中的较小值
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int value = f(i, j, mid);
                if (value == x) {
                    count++;
                    break; // 找到一个解后可以退出，因为题目是统计不同的 (i, j, k)
                }
                else if (value < x) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false); // 提高 cin/cout 性能
    cin.tie(nullptr);

    int t;
    cin >> t; // 读取测试数据的组数
    vector<int> results;

    while (t--) {
        int n, m, p, x;
        cin >> n >> m >> p >> x; // 读取每组数据
        results.push_back(process(n, m, p, x)); // 处理每组数据
    }

    // 输出所有结果
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
