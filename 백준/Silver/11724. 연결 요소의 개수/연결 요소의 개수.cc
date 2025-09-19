#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

// 시간 복잡도 : O(1)

void BFS(vector<bool>& visit, const vector<vector<int>>& graph, int v)
{
	visit[v] = true;
	queue<int> q;
	q.push(v);

	while (!q.empty())
	{
		int curV = q.front();
		q.pop();

		for (int i = 0; i < graph[curV].size(); ++i)
		{
			if (visit[graph[curV][i]]) continue;
			visit[graph[curV][i]] = true;
			q.push(graph[curV][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	int answer = 0;

	vector<bool> visit(N, false);
	vector<vector<int>> graph(N);
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < N; ++i)
	{
		if (visit[i]) continue;
		BFS(visit,graph,i);
		answer++;
	}

	cout << answer << endl;

	return 0;
}
