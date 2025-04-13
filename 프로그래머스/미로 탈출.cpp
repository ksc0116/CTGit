// https://school.programmers.co.kr/learn/courses/30/lessons/159993
// 최종 : O(N^2)

#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<bool>> visit;
int Go(const pair<int, int>& start, const pair<int, int>& end, const vector<string>& maps)
{
	queue<tuple<int, int, int>> q;
	q.push({ start.first,start.second,0 });
	visit[start.first][start.second] = true;

	while (!q.empty())
	{
		auto [cur_y, cur_x, depth] = q.front();
		q.pop();

		if (cur_x == end.second && cur_y == end.first) return depth;

		for (int i = 0; i < 4; ++i)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];

			if (n_x < 0 || n_x > maps[0].size() - 1 || n_y < 0 || n_y > maps.size() - 1)
				continue;

			if (maps[n_y][n_x] == 'X') continue;
			if (visit[n_y][n_x]) continue;

			visit[n_y][n_x] = true;
			q.push({ n_y,n_x,depth + 1 });
		}
	}

	return -1;
}

int solution(vector<string> maps)
{
	int answer = 0;
	visit.resize(maps.size(), vector<bool>(maps[0].size(), false));
	pair<int, int> startPoint;
	pair<int, int> leverPoint;
	pair<int, int> doorPoint;
	for (int i = 0; i < maps.size(); ++i)
	{
		for (int j = 0; j < maps[i].size(); ++j)
		{
			if (maps[i][j] == 'L')
				leverPoint = { i,j };
			else if (maps[i][j] == 'E')
				doorPoint = { i,j };
			else if (maps[i][j] == 'S')
				startPoint = { i,j };
		}
	}
	// 시작 - 레버까지의 최단 거리
	int result = Go(startPoint, leverPoint, maps);
	if (result == -1) return -1;
	answer += result;

	fill(visit.begin(), visit.end(), vector<bool>(maps[0].size(), false));
	// 레버 - 문까지의 최단 거리
	result = Go(leverPoint, doorPoint, maps);
	if (result == -1) return -1;
	answer += result;
	return answer;
}