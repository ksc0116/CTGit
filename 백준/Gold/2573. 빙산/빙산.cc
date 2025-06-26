#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void DFS(int row, int col,const vector<vector<int>>& ice, vector<vector<bool>>& visit, vector<vector<int>>& tmpIce)
{
	int cur_x = col;
	int cur_y = row;

	visit[cur_y][cur_x] = true;

	int waterCnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		int n_x = col + dx[i];
		int n_y = row + dy[i];

		if (n_x < 0 || n_x >= ice[0].size() || n_y < 0 || n_y >= ice.size()) continue;
		if (visit[n_y][n_x]) continue;
		if (ice[n_y][n_x] == 0)
		{
			waterCnt++;
			continue;
		}

		DFS(n_y, n_x, ice, visit,tmpIce);
	}

	tmpIce[cur_y][cur_x] -= waterCnt;
	if (tmpIce[cur_y][cur_x] < 0)
	{
		tmpIce[cur_y][cur_x] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> ice(N, vector<int>(M));

	for (int i = 0; i < ice.size(); ++i)
	{
		for (int j = 0; j < ice[0].size(); ++j)
		{
			cin >> ice[i][j];
		}
	}
	int answer = 0;
	int cnt = 0;
	while (cnt < 2)
	{
		cnt = 0;
		bool isNum = false;
		vector<vector<bool>> visit(N, vector<bool>(M));
		vector<vector<int>> tmpIce = ice;

		for (int i = 0; i < ice.size(); ++i)
		{
			for (int j = 0; j < ice[0].size(); ++j)
			{
				if (ice[i][j] == 0) continue;
				if (visit[i][j]) continue;

				isNum = true;
				DFS(i,j,ice, visit,tmpIce);
				cnt++;
			}
		}
		if (!isNum)
		{
			cout << 0 << endl;
			return 0;
		}
		if (cnt >= 2)
		{
			break;
		}

		ice = tmpIce;
		answer++;
	}
	cout << answer << endl;
	return 0;
}