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

void DFS(const vector<vector<int>>& board, vector<vector<bool>>& visit, int y, int x, int& depth)
{
	if (visit[y][x]) return;
	visit[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size()) continue;
		if (visit[ny][nx]) continue;
		if (board[ny][nx] == 0) continue;

		DFS(board, visit, ny, nx, ++depth);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	vector<int> answer(2, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int val = 0;
			cin >> val;
			board[i][j] = val;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 1 && !visit[i][j])
			{
				int depth = 1;
				DFS(board,visit,i,j, depth);
				answer[0]++;
				answer[1] = max(answer[1], depth);
			}
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}

