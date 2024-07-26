#include <bits/stdc++.h>
using namespace std;

struct Game {
    int L, R;
};

// ����������򣬰���ʼʱ��������������ʼʱ����ͬ�򰴽���ʱ����������
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

    // ����ʼʱ����������ʼʱ����ͬ�򰴽���ʱ������
    sort(games.begin(), games.end(), order);

    int count = 0;
    int size = N;

    while (size > 0) {
        int next = games[0].R;
        count++; // ѡ��ǰ����

        int i = 1;
        while (i < size && games[i].L < next) {
            if (games[i].R < next) {
                next = games[i].R;
                games.erase(games.begin()); // �Ƴ���ǰ����
                size--;
            }
            else {
                games.erase(games.begin() + i); // �Ƴ���ͻ����
                size--;
            }
        }
        games.erase(games.begin()); // �Ƴ���ǰѡ��ı���
        size--;
    }

    cout << count << endl;

    return 0;
}
