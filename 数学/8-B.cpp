#include <bits/stdc++.h>
using namespace std;

// �������Լ��
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// ������С������
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int x, y;
    cin >> x >> y;

    vector<pair<int, int>> results;

    // ����a1�����п���ֵ����x��ʼ����xΪ����
    for (int a1 = x; a1 <= (y / 2); a1 += x) {
        // ȷ��y��a1�ı�������������ȷ��a2������
        if (y % (a1 / x) == 0) {
            int a2 = (y * x) / a1; // �����Ӧ��a2
            if (gcd(a1, a2) == x && lcm(a1, a2) == y) {
                results.emplace_back(a1, a2);
                if (a1 != a2) { // ȷ�����ظ���¼��ͬ�����
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
