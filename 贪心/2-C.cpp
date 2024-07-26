#include <bits/stdc++.h>
using namespace std;

struct Game {
    int L, R;
};

bool order(Game a, Game b) {
    if (a.L != b.L)
        return a.L < b.L;
    return a.R < b.R;
}

int main() {
    int N, T;
    cin >> N >> T;

    vector<Game> games(N);
    for (int i = 0; i < N; ++i) {
        cin >> games[i].L >> games[i].R;
        games[i].R = games[i].R + T;
    }

    sort(games.begin(), games.end(), order);

    int count = 0;
    int size = N;

    while (size > 0) {
        int next = games[0].R;
        count++;

        int i = 1;
        while (i < size && games[i].L < next) {
            if (games[i].R < next) {
                next = games[i].R;
                games.erase(games.begin());
                size--;
            }
            else {
                games.erase(games.begin() + i);
                size--;
            }
        }
        games.erase(games.begin());
        size--;
    }

    cout << count << endl;

    return 0;
}
