#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    // 从标准输入读取字符串
    cin >> S;

    set<string> sub;

    // 枚举所有可能的子字符串
    for (int i = 0; i < S.length(); ++i) {
        for (int j = 1; j <= S.length() - i; ++j) {
            sub.insert(S.substr(i, j));
        }
    }

    // 输出不同子字符串的数量
    cout << sub.size() << endl;

    return 0;
}
