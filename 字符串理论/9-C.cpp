#include <bits/stdc++.h>
using namespace std;

int main() {
    int length;
    scanf_s("%d", &length);

    vector<int> results(length + 2, 0);
    int count = 0;

    // 计算每个间隔距离下的樱花数量
    for (int d = 1; d <= length; d++) {
        int n = length / d;
        if ((n + 1) * d > length) {
            results[n + 1] += 1;
        }
    }

    // 计算可能的樱花数量种类
    for (int i = 2; i <= length + 1; i++) {
        if (results[i] != 0) {
            count++;
        }
    }

    // 使用字符串流来拼接输出
    stringstream ss;
    ss << count << "\n";
    for (int i = length + 1; i >= 2; i--) {
        if (results[i] != 0) {
            ss << i << " " << results[i] << "\n";
        }
    }

    // 一次性输出所有内容
    printf("%s", ss.str().c_str());

    return 0;
}
