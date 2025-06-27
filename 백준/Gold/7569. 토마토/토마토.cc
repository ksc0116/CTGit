#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int M, N, H;
int dx[] = { -1,1,0,0 ,0,0 };
int dy[] = { 0,0,-1,1 ,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

struct info
{
	info(int i, int j, int k, int day) :i(i), j(j), k(k), day(day) {}
	int i, j, k, day;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;

	bool isFirst = true;
	vector<vector<vector<int>>> tomato(H, vector<vector<int>>(N, vector<int>(M)));
	queue<info> q;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
				{
					q.emplace(i, j, k, 0);
				}
				else if (tomato[i][j][k] == 0)
				{
					isFirst = false;
				}
			}
		}
	}
	if (isFirst)
	{
		cout << 0 << endl;
		return 0;
	}
	int day = 0;
	while (!q.empty())
	{
		auto front = q.front();
		q.pop();

		day = front.day;
		int cz = front.i;
		int cy = front.j;
		int cx = front.k;
		for (int i = 0; i < 6; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
			if (tomato[nz][ny][nx] == 1 || tomato[nz][ny][nx] == -1) continue;
			tomato[nz][ny][nx] = 1;
			q.emplace(nz, ny, nx, day + 1);
		}
	}
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (tomato[i][j][k] == 0)
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}

	cout << day << endl;

	return 0;
}