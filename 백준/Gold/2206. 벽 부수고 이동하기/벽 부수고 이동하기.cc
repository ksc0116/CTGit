#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <limits.h>

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
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2)));

	queue<pair<pair<int, int>,int>> q;
	dist[0][0][0] = 1;
	q.push({{ 0,0 }, 0});

	while (!q.empty())
	{
		int crashed = q.front().second;
		int cx = q.front().first.second;
		int cy = q.front().first.first;
		q.pop();

		if (cx == M - 1 && cy == N - 1)
		{
			cout << dist[cy][cx][crashed] << endl;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

			if (board[ny][nx] == '0' && dist[ny][nx][crashed] == 0)
			{
				q.push({ {ny,nx}, crashed });
				dist[ny][nx][crashed] = dist[cy][cx][crashed] + 1;
			}

			if (crashed == 0 && board[ny][nx] == '1' && dist[ny][nx][1] == 0)
			{
				q.push({ {ny,nx}, 1 });
				dist[ny][nx][1] = dist[cy][cx][crashed] + 1;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
