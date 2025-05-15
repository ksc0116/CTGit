// https://school.programmers.co.kr/learn/courses/30/lessons/250125
// 시간 복잡도 : O(1)

#include <string>
#include <vector>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int solution(vector<vector<string>> board, int h, int w)
{
	int answer = 0;

	string curColor = board[h][w];

	for (int i = 0; i < 4; ++i)
	{
		int n_x = w + dx[i];
		int n_y = h + dy[i];

		if (n_x < 0 || n_y < 0 || n_x > board[0].size() - 1 || n_y > board.size() - 1)
		{
			continue;
		}

		if (curColor == board[n_y][n_x])
		{
			answer++;
		}
	}

	return answer;
}