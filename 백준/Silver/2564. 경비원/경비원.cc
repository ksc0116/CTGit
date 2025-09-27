#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int constexpr UP = 1;
int constexpr DOWN = 2;
int constexpr LEFT = 3;
int constexpr RIGHT = 4;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C, R; // C: 가로 길이, R: 세로 길이
    cin >> C >> R;

    int storeCnt;
    cin >> storeCnt;

    vector<int> stores;
    int totalPerimeter = 2 * (C + R);

    // 상점들 입력
    for (int i = 0; i < storeCnt; ++i)
    {
        int dir, val;
        cin >> dir >> val;

        int dist = 0;
        if (dir == UP)        dist = val;
        else if (dir == RIGHT) dist = C + val;
        else if (dir == DOWN)  dist = C + R + (C - val);
        else if (dir == LEFT)  dist = 2 * C + R + (R - val);

        stores.push_back(dist);
    }

    // 경비원 위치 입력
    int dir, val;
    cin >> dir >> val;

    int guardDist = 0;
    if (dir == UP)        guardDist = val;
    else if (dir == RIGHT) guardDist = C + val;
    else if (dir == DOWN)  guardDist = C + R + (C - val);
    else if (dir == LEFT)  guardDist = 2 * C + R + (R - val);

    long long answer = 0;

    // 각 상점까지 최소 거리 계산
    for (int storeDist : stores)
    {
        int diff = abs(guardDist - storeDist);
        answer += min(diff, totalPerimeter - diff);
    }

    cout << answer << "\n";

    return 0;
}