#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    
    long long result = 0;
    a = a % p;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % p;
        }

        a = (a * 2) % p;
        b /= 2;
    }

    cout << result;

    return 0;
}
