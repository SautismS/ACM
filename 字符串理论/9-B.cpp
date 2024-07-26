#include <bits/stdc++.h>
using namespace std;

int main() {
    string A1, B1;
    cin >> A1 >> B1;

    string A2 = A1 + A1;
    string B2 = B1;
    reverse(B2.begin(), B2.end());

    if (A2.find(B1) != string::npos || A2.find(B2) != string::npos) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
