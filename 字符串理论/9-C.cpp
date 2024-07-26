#include <bits/stdc++.h>
using namespace std;

int main() {
    int length;
    scanf_s("%d", &length);

    vector<int> results(length + 2, 0);
    int count = 0;

    // ����ÿ����������µ�ӣ������
    for (int d = 1; d <= length; d++) {
        int n = length / d;
        if ((n + 1) * d > length) {
            results[n + 1] += 1;
        }
    }

    // ������ܵ�ӣ����������
    for (int i = 2; i <= length + 1; i++) {
        if (results[i] != 0) {
            count++;
        }
    }

    // ʹ���ַ�������ƴ�����
    stringstream ss;
    ss << count << "\n";
    for (int i = length + 1; i >= 2; i--) {
        if (results[i] != 0) {
            ss << i << " " << results[i] << "\n";
        }
    }

    // һ���������������
    printf("%s", ss.str().c_str());

    return 0;
}
