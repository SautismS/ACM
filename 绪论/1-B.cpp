#include <bits/stdc++.h>

using namespace std;

// �ֶ�ʵ�� gcd ���������������������Լ��
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ����һ���ṹ�����洢�������������ʽ
struct Fraction {
    long long a, b;

    // ���캯��
    Fraction(long long a, long long b) : a(a), b(b) {
        simplify();
    }

    // �򻯷���
    void simplify() {
        long long gcd_ab = gcd(a, b);
        a /= gcd_ab;
        b /= gcd_ab;
    }

    // ��������أ���������
    bool operator<(const Fraction& other) const {
        // �Ƚ����������Ĵ�С a/b > other.a/other.b
        return a * other.b > other.a * b;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Fraction> lands;

    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        lands.emplace_back(a, b);
    }

    // ����ش�С��������
    sort(lands.begin(), lands.end());

    // ������
    for (const auto& land : lands) {
        cout << land.a << "/" << land.b << endl;
    }

    return 0;
}
