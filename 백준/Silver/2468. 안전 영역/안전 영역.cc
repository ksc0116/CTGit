#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void BFS(const vector<vector<int>>& board, vector<vector<bool>>& visit, int x, int y)
{
	queue<pair<int, int>> q;
	q.push({y, x});
	visit[y][x] = true;

	while (!q.empty())
	{
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size()) continue;
			if (visit[ny][nx]) continue;

			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

int Simulate(const vector<vector<int>>& board, vector<vector<bool>>& visit)
{
	int cnt = 0;

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (visit[i][j]) continue;
			cnt++;
			BFS(board,visit,j,i);
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> board(N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int val = 0;
			cin >> val;

			board[i].push_back(val);
		}
	}

	int answer = 0;

	for (int i = 0; i <= 100; ++i)
	{
		int curHeight = i;

		vector<vector<bool>> visit(N, vector<bool>(N, false));
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				if (board[j][k] <= curHeight)
				{
					visit[j][k] = true;
				}
			}
		}
		answer = max(answer, Simulate(board, visit));
	}

	cout << answer << endl;

	return 0;
}
