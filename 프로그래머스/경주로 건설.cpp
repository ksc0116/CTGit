// https://school.programmers.co.kr/learn/courses/30/lessons/67259
// 시간 복잡도 : O(N^2)

#include <cstring>
#include <vector>
#include <queue>
#include <memory>
#include <tuple>
#include <limits.h>

using namespace std;
constexpr int MAX = 26;
constexpr int STRAIGHT_COST = 100;
constexpr int CORNER_COST = 600;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cost[MAX][MAX][4];

int solution(vector<vector<int>> board)
{
	int answer = INT_MAX;
	memset(cost, -1, sizeof(cost));

	// y, x, dir
	queue<tuple<int, int, int>> q;

	cost[0][0][1] = 0;
	cost[0][0][3] = 0;

	q.push({ 0,0,1 });
	q.push({ 0,0,3 });

	while (!q.empty())
	{
		auto [cy, cx, dir] = q.front();
		q.pop();
		int curCost = cost[cy][cx][dir];
		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx < 0 || nx > board[0].size() - 1 || ny < 0 || ny > board.size() - 1) continue;
			if (board[ny][nx]) continue;

			int newCost = curCost + (i == dir ? STRAIGHT_COST : CORNER_COST);
			if (cost[ny][nx][i] == -1 || cost[ny][nx][i] > newCost)
			{
				q.push({ ny,nx,i });
				cost[ny][nx][i] = newCost;
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (cost[board.size() - 1][board.size() - 1][i] != -1)
			answer = min(answer, cost[board.size() - 1][board.size() - 1][i]);
	}
	return answer;
}