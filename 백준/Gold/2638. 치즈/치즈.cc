#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <limits.h>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> cheese;

int N, M;
int totalCnt = 0;

void DFS(int curX, int curY, vector<vector<bool>>& visit, vector<vector<int>>& board)
{
	visit[curY][curX] = true;
	board[curY][curX] = 2;
	for (int i = 0; i < 4; ++i)
	{
		int nx = curX + dx[i];
		int ny = curY + dy[i];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (visit[ny][nx]) continue;
		if (board[ny][nx] == 1) continue;
		DFS(nx, ny, visit, board);
	}
}

void DeleteCheese(vector<vector<int>>& board)
{
	vector<vector<bool>> visit(N,vector<bool>(M));
	for (int i = 0; i < cheese.size(); ++i)
	{
		int cx = cheese[i].second;
		int cy = cheese[i].first;

		if (cx == -1 && cy == -1) continue;
		
		visit[cy][cx] = true;

		int cnt = 0;

		for (int j = 0; j < 4; ++j)
		{
			int nx = cx + dx[j];
			int ny = cy + dy[j];

			if (visit[ny][nx]) continue;

			if (board[ny][nx] == 2)
			{
				cnt++;
				if (cnt == 2)
				{
					totalCnt--;
					cheese[i].first = -1;
					cheese[i].second = -1;
					board[cy][cx] = 0;
					break;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				totalCnt++;
				cheese.push_back({ i,j });
			}
		}
	}
	int answer = 0;
	while (totalCnt > 0)
	{
		answer++;
		vector<vector<bool>> visit(N, vector<bool>(M));
		// 외부 공기 판단하는 부분
		DFS(0, 0, visit, board);

		// 치즈 제거 부분
		DeleteCheese(board);
	}

	cout << answer << endl;

	return 0;
}
