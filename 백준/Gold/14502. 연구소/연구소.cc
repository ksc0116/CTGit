#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

int answer = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void BFS(vector<vector<int>>& board, int y, int x, vector<vector<bool>>& visit)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[y][x] = true;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size()) continue;
			if (board[ny][nx] == 1 || board[ny][nx] == 2) continue;
			if (visit[ny][nx]) continue;

			visit[ny][nx] = true;
			board[ny][nx] = 2;
			q.push({ nx,ny });
		}
	}
}

int Simulate(const vector<vector<int>>& board, vector<pair<int, int>>& wall)
{
	vector<vector<int>> tmpBoard = board;
	vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

	for (int i = 0; i < wall.size(); ++i)
	{
		int x = wall[i].first;
		int y = wall[i].second;
		tmpBoard[y][x] = 1;
	}

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (visit[i][j] || tmpBoard[i][j] == 1 || tmpBoard[i][j] == 0) continue;

			BFS(tmpBoard,i,j, visit);
		}
	}

	// 0 갯수
	int cnt = 0;
	for (int i = 0; i < tmpBoard.size(); ++i)
	{
		for (int j = 0; j < tmpBoard[i].size(); ++j)
		{
			if (tmpBoard[i][j] == 0)
			{
				cnt++;
			}
		}
	}

	return cnt;
}

void DFS(const vector<pair<int, int>>& empty, const vector<vector<int>>& board, int start, int depth, vector<pair<int,int>>& wall)
{
	if (depth == 3)
	{
		answer = max(answer, Simulate(board, wall));
		return;
	}

	for (int i = start; i < empty.size(); ++i)
	{
		int x = empty[i].first;
		int y = empty[i].second;

		wall.push_back({ x,y });
		DFS(empty, board, i + 1, depth + 1, wall);
		wall.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M));
	vector<pair<int, int>> wall;
	vector<pair<int, int>> empty;
	vector<pair<int, int>> virus;


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int val = 0;
			cin >> val;
			if (val == 0)
			{
				empty.push_back({j,i});
			}
			else if (val == 2)
			{
				virus.push_back({ j,i });
			}

			board[i][j] = val;
		}
	}

	DFS(empty, board, 0, 0,wall);

	cout << answer << endl;

	return 0;
}
