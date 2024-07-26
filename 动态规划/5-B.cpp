#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N; // 输入邀请的总人数N

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i]; // 输入第i个人获得的快感值a_i
    }

    vector<long long> dp; // 用于存储当前选择的快感值序列

    for (int i = 0; i < N; i++) {
        // 使用lower_bound找到第一个大于等于a[i]的位置
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) {
            // 如果没有找到，则将当前快感值加入dp末尾
            dp.push_back(a[i]);
        }
        else {
            // 如果找到了，则用当前快感值替换该位置上的值
            *it = a[i];
        }
    }

    cout << dp.size() << endl; // 输出qz最多可以咕掉多少人

    return 0;
}
