#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> v(n + 1, false);
    queue<int> q;
    q.push(1);
    v[1] = true;
    int step = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int robot = q.front();
            q.pop();

            if (robot == n) {
                cout << step << endl;
                return 0;
            }

            if (robot + 1 <= n && !v[robot + 1]) {
                q.push(robot + 1);
                v[robot + 1] = true;
            }

            if (2 * robot <= n && !v[2 * robot]) {
                q.push(2 * robot);
                v[2 * robot] = true;
            }

            if (robot - 1 >= 1 && !v[robot - 1]) {
                q.push(robot - 1);
                v[robot - 1] = true;
            }
        }
        step++;
    }

    return 0;
}
