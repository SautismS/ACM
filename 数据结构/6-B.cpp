#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int result = 0;
    for (int i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }

    cout << result + 1 << endl;

    return 0;
}
