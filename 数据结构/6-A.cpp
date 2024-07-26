#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // 括号序列的长度
    cin >> n;

    string brackets; // 括号序列
    cin >> brackets;

    stack<int> s; // 用于存储左括号的位置
    vector<int> result(n, 0); // 用于存储每个左括号对应的右括号的位置

    // 遍历括号序列
    for (int i = 0; i < n; ++i) {
        if (brackets[i] == '(') {
            // 如果是左括号，压入栈中
            s.push(i + 1);
        }
        else {
            // 如果是右括号，弹出栈顶元素并记录对应位置
            result[s.top() - 1] = i + 1; // 用 s.top() - 1 作为索引存储对应右括号的位置
            s.pop();
        }
    }

    // 输出结果
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] != 0) {
            cout << result[i] << " ";
        }
    }

    return 0;
}
