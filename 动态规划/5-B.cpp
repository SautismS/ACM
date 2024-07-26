#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N; // ���������������N

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i]; // �����i���˻�õĿ��ֵa_i
    }

    vector<long long> dp; // ���ڴ洢��ǰѡ��Ŀ��ֵ����

    for (int i = 0; i < N; i++) {
        // ʹ��lower_bound�ҵ���һ�����ڵ���a[i]��λ��
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) {
            // ���û���ҵ����򽫵�ǰ���ֵ����dpĩβ
            dp.push_back(a[i]);
        }
        else {
            // ����ҵ��ˣ����õ�ǰ���ֵ�滻��λ���ϵ�ֵ
            *it = a[i];
        }
    }

    cout << dp.size() << endl; // ���qz�����Թ���������

    return 0;
}
