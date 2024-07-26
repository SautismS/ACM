#include <bits/stdc++.h>

using namespace std;

// 手动实现 gcd 函数，计算两个数的最大公约数
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 定义一个结构体来存储分数及其最简形式
struct Fraction {
    long long a, b;

    // 构造函数
    Fraction(long long a, long long b) : a(a), b(b) {
        simplify();
    }

    // 简化分数
    void simplify() {
        long long gcd_ab = gcd(a, b);
        a /= gcd_ab;
        b /= gcd_ab;
    }

    // 运算符重载，用于排序
    bool operator<(const Fraction& other) const {
        // 比较两个分数的大小 a/b > other.a/other.b
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

    // 对领地大小进行排序
    sort(lands.begin(), lands.end());

    // 输出结果
    for (const auto& land : lands) {
        cout << land.a << "/" << land.b << endl;
    }

    return 0;
}
