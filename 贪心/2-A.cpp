#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    long N;
    cin >> K;
    cin >> N;

    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }

    sort(W.begin(), W.end());

    int B = 0;
    int i = 0, j = N - 1;

    while (i <= j) {
        if (W[i] + W[j] <= K) {
            i++;
            j--;
        }
        else {
            j--;
        }
        B++;
    }

    cout << B << endl;

    return 0;
}
