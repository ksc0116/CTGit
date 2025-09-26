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

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

vector<string> BOMB(const vector<string>& board)
{
	vector<string> res(board.size(), string(board[0].size(), 'O'));

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == 'O')
			{
				res[i][j] = '.';
				for (int k = 0; k < 4; ++k)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()) continue;

					res[ny][nx] = '.';
				}
			}
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C, N;
	cin >> R >> C >> N;

	vector<string> board(R);
	vector<pair<int, int>> bomb;
	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == 'O')
			{
				bomb.push_back({ i,j });
			}
		}
	}
	if (N % 2 == 0)
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cout << "O";
			}
			cout << "\n";
		}
		return 0;
	}


	if (N == 1)
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cout << board[i][j];
			}
			cout << "\n";
		}
	}
	else if (N % 4 == 1)
	{
		vector<string> res = BOMB(board);
		res = BOMB(res);
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cout << res[i][j];
			}
			cout << "\n";
		}
	}
	else if( N % 4 == 3)
	{
		vector<string> res = BOMB(board);
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cout << res[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}

