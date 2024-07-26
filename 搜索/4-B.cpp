#include <bits/stdc++.h>
using namespace std;

int b;

int main() {
    long long n;
    cin >> n;

    long long left = 1, right = n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        cout << "? " << left << " " << mid << endl;

        int j;
        cin >> j;

        if (j == 1) {
            right = mid;
        }
        else {
            left = mid + 1;
        }

        if (left == right) {
            break;
        }
    }

    cout << "! " << left << endl;

    return 0;
}
