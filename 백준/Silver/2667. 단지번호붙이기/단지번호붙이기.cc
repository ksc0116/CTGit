#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


using namespace std;
int BFS(const vector<string>& board, vector<vector<bool>>& visit,int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[y][x] = true;
	int cnt = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size()) continue;
			if (visit[ny][nx] || board[ny][nx] == '0') continue;
			visit[ny][nx] = true;
			q.push({ nx,ny });
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<string> board(N);
	vector<vector<bool>> visit(N, vector<bool>(N,false));
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}
	int cnt = 0;
	vector<int> answer;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == '0' || visit[i][j]) continue;

			cnt++;
			answer.push_back(BFS(board,visit, j,i));
		}
	}
	cout << cnt << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}

	return 0;
}
