#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // �������еĳ���
    cin >> n;

    string brackets; // ��������
    cin >> brackets;

    stack<int> s; // ���ڴ洢�����ŵ�λ��
    vector<int> result(n, 0); // ���ڴ洢ÿ�������Ŷ�Ӧ�������ŵ�λ��

    // ������������
    for (int i = 0; i < n; ++i) {
        if (brackets[i] == '(') {
            // ����������ţ�ѹ��ջ��
            s.push(i + 1);
        }
        else {
            // ����������ţ�����ջ��Ԫ�ز���¼��Ӧλ��
            result[s.top() - 1] = i + 1; // �� s.top() - 1 ��Ϊ�����洢��Ӧ�����ŵ�λ��
            s.pop();
        }
    }

    // ������
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] != 0) {
            cout << result[i] << " ";
        }
    }

    return 0;
}
