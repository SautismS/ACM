#include <bits/stdc++.h>
using namespace std;

inline int f(int i, int j, int k) {
    return 2 * i * i + 2 * j * j + k * k + i * j + 2 * i * k + 2 * j * k;
}

int process(int n, int m, int p, int x) {
    int count = 0;
    int sqrt_x = sqrt(x) + 1; // ���� sqrt(x) ����1�����ڼ���ѭ����Χ

    for (int i = 1; i <= n && i <= sqrt_x; ++i) {
        for (int j = 1; j <= m && j <= sqrt_x; ++j) {
            int left = 1;
            int right = min(sqrt_x, p); // �� right ����Ϊ sqrt(x) �� p �еĽ�Сֵ
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int value = f(i, j, mid);
                if (value == x) {
                    count++;
                    break; // �ҵ�һ���������˳�����Ϊ��Ŀ��ͳ�Ʋ�ͬ�� (i, j, k)
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
    ios::sync_with_stdio(false); // ��� cin/cout ����
    cin.tie(nullptr);

    int t;
    cin >> t; // ��ȡ�������ݵ�����
    vector<int> results;

    while (t--) {
        int n, m, p, x;
        cin >> n >> m >> p >> x; // ��ȡÿ������
        results.push_back(process(n, m, p, x)); // ����ÿ������
    }

    // ������н��
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
