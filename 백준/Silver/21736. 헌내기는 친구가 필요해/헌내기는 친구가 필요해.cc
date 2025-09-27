#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

// 시간 복잡도 : N^2

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void DFS(const vector<string>& board, vector<vector<bool>>& visit, int y, int x, int& answer)
{
	if (visit[y][x]) return;
	visit[y][x] = true;
	if (board[y][x] == 'P')
	{
		answer++;
	}

	int cy = y;
	int cx = x;

	for (int i = 0; i < 4; ++i)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size()) continue;
		if (board[ny][nx] == 'X') continue;

		DFS(board, visit, ny,nx,answer);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N , M;
	cin >> N >> M;

	vector<string> board(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 'I')
			{
				vector<vector<bool>> visit(N, vector<bool>(M, false));
				DFS(board, visit, i, j, answer);
				if (answer != 0)
					cout << answer << "\n";
				else
					cout << "TT" << "\n";
				return 0;
			}
		}
	}

	return 0;
}
