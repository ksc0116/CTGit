// https://school.programmers.co.kr/learn/courses/30/lessons/1844?language=cpp
// 시간 복잡도 : O(N * M)

#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<vector<bool>> visit;

int BFS(const vector<vector<int>>& maps)
{
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,1 });

	while (!q.empty())
	{
		auto [cy, cx, depth] = q.front();
		q.pop();

		if (cx == maps[0].size() - 1 && cy == maps.size() - 1) return depth;

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx > maps[0].size() - 1 || ny < 0 || ny > maps.size() - 1)
			{
				continue;
			}
			if (visit[ny][nx]) continue;
			if (maps[ny][nx] == 0) continue;

			visit[ny][nx] = true;
			q.push({ ny,nx,depth + 1 });
		}
	}

	return -1;
}

int solution(vector<vector<int> > maps)
{
	int answer = 0;

	visit.resize(maps.size(), vector<bool>(maps[0].size(), false));

	int result = BFS(maps);

	return result == -1 ? -1 : result;
}