#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <limits.h>

// 시간 복잡도 : N^M

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<string> board(N);
	vector<vector<int>> dist(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	queue<pair<int, int>> able;

	dist[0][0] = 1;
	able.push({ 0,0 });

	while (!able.empty())
	{
		int cx = able.front().first;
		int cy = able.front().second;
		able.pop();
		if (cx == M - 1 && cy == N - 1)
		{
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N || board[ny][nx] == '0' || dist[ny][nx] != 0)
			{
				continue;
			}

			able.push({ nx,ny });
			dist[ny][nx] = dist[cy][cx] + 1;
		}
	}


	cout << dist[N - 1][M - 1] << endl;

	return 0;
}
