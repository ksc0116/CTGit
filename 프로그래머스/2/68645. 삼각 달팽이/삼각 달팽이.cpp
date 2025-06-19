#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    int num = 1;

    // 삼각형 모양의 2차원 벡터 초기화
    vector<vector<int>> tmpVec(n);
    for (int i = 0; i < n; ++i)
    {
        tmpVec[i].resize(i + 1);
    }

    int y = -1, x = 0;  // y: 행, x: 열
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i % 3 == 0)
            {
                // 아래로 이동 (행 증가)
                y++;
            }
            else if (i % 3 == 1)
            {
                // 오른쪽으로 이동 (열 증가)
                x++;
            }
            else
            {
                // 대각선 위로 이동 (행 감소, 열 감소)
                y--;
                x--;
            }
            tmpVec[y][x] = num++;
        }
    }

    // 2차원 배열을 1차원으로 변환
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < tmpVec[i].size(); ++j)
        {
            answer.push_back(tmpVec[i][j]);
        }
    }

    return answer;
}
