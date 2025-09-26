#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

// 시간 복잡도 : N^2

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int DFS(int y, int x, vector<vector<int>>& DP, const vector<vector<int>>& board)
{
	if (DP[y][x] != 0) return DP[y][x];

	DP[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || ny < 0 || nx >= (int)board[0].size() || ny >= (int)board.size()) continue;
		if (board[y][x] >= board[ny][nx]) continue;

		DP[y][x] = max(DP[y][x], 1 + DFS(ny, nx, DP, board));
	}

	return DP[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> board(n,vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int val;
			cin >> val;

			board[i][j] = val;
		}
	}
	vector<vector<int>> DP(n, vector<int>(n));
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			answer = max(answer, DFS(i, j,DP,board));
		}
	}
	cout << answer << "\n";
	return 0;
}

