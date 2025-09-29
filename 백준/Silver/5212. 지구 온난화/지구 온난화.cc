#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>
#include <limits.h>
using namespace std;


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C;
	cin >> R >> C;

	vector<string> board(R);
	vector<string> tmpBoard(R);
	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
	}
	tmpBoard = board;

	int minX = INT_MAX;
	int maxX = INT_MIN;
	int minY = INT_MAX;
	int maxY = INT_MIN;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'X')
			{
				int cnt = 0; // 바다/밖 개수 세기

				for (int k = 0; k < 4; ++k)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (nx < 0 || ny < 0 || nx >= C || ny >= R) {
						cnt++;
						continue;
					}

					if (board[ny][nx] == '.') cnt++;
				}

				if (cnt < 3)  // 바다/밖이 0,1,2개 → 살아남음
				{
					minX = min(minX, j);
					maxX = max(maxX, j);
					minY = min(minY, i);
					maxY = max(maxY, i);
				}
				else
				{
					tmpBoard[i][j] = '.';
				}
			}
		}
	}

	for (int i = 0; i < R; ++i)
	{
		bool isN = false;
		for (int j = 0; j < C; ++j)
		{
			if (i >= minY && i <= maxY && j >= minX && j <= maxX)
			{
				isN = true;
				cout << tmpBoard[i][j];
			}
		}
		if(isN)
			cout << "\n";
	}

	return 0;
}
