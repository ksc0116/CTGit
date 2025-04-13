// https://school.programmers.co.kr/learn/courses/30/lessons/43162
// 시간 복잡도 : O(N)

#include <string>
#include <vector>

using namespace std;

void DFS(int start, vector<vector<int>>& graph, vector<bool>& visit)
{
	visit[start] = true;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		if (visit[graph[start][i]]) continue;

		DFS(graph[start][i], graph, visit);
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	vector<vector<int>> graph(n);
	vector<bool> visit(n, false);

	for (int i = 0; i < computers.size(); ++i)
	{
		for (int j = 0; j < computers[i].size(); ++j)
		{
			if (computers[i][j])
			{
				graph[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < visit.size(); ++i)
	{
		if (!visit[i])
		{
			answer++;
			DFS(i, graph, visit);
		}
	}
	return answer;
}