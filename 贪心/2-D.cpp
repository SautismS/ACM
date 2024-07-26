#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long L, R;
    cin >> L >> R;

    int lower = 0;
    int upper = 0;
    int count = 0;

    for (int i = 0; i <= 63; i++) {
        if (R >> i == 0) {
            upper = i;
            break;
        }
    }

    for (int i = upper - 1; i >= 0; i--) {
        if (R >> i != L >> i) {
            lower = i;
            count = i;
            for (int j = 0; j <= i; j++) {
                if (!(R & (static_cast<unsigned long long>(1) << j))) {
                    break;
                }
                if (j == i) {
                    count++;
                }
            }
            break;
        }
    }

    for (int i = lower + 1; i < upper; i++) {
        if (L & static_cast<unsigned long long>(1) << i) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
