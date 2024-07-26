#include <bits/stdc++.h>
using namespace std;

struct Game {
    int L, R;
};

// 比赛排序规则，按开始时间升序排序，若开始时间相同则按结束时间升序排序
bool order(const Game& a, const Game& b) {
    if (a.L != b.L)
        return a.L < b.L;
    return a.R < b.R;
}

int main() {
    int N;
    cin >> N;

    vector<Game> games(N);
    for (int i = 0; i < N; ++i) {
        cin >> games[i].L >> games[i].R;
    }

    // 按开始时间排序，若开始时间相同则按结束时间排序
    sort(games.begin(), games.end(), order);

    int count = 0;
    int size = N;

    while (size > 0) {
        int next = games[0].R;
        count++; // 选择当前比赛

        int i = 1;
        while (i < size && games[i].L < next) {
            if (games[i].R < next) {
                next = games[i].R;
                games.erase(games.begin()); // 移除当前比赛
                size--;
            }
            else {
                games.erase(games.begin() + i); // 移除冲突比赛
                size--;
            }
        }
        games.erase(games.begin()); // 移除当前选择的比赛
        size--;
    }

    cout << count << endl;

    return 0;
}
