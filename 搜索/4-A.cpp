#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 0;
    vector<int> k;

    for (int i = 1; i < n; i <<= 1) {
        ++m;
        k.push_back(i);
    }

    cout << m << endl;
    for (int i = 0; i < k.size(); ++i) {
        cout << k[i] << " ";
    }
    cout << endl;

    return 0;
}
