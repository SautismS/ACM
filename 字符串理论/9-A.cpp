#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    // �ӱ�׼�����ȡ�ַ���
    cin >> S;

    set<string> sub;

    // ö�����п��ܵ����ַ���
    for (int i = 0; i < S.length(); ++i) {
        for (int j = 1; j <= S.length() - i; ++j) {
            sub.insert(S.substr(i, j));
        }
    }

    // �����ͬ���ַ���������
    cout << sub.size() << endl;

    return 0;
}
