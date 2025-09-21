#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

// 시간 복잡도 : V + E


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;

	vector<vector<int>> graph(N);
	vector<int> vertex(N);
	for (int i = 0; i < N - 1; ++i)
	{
		int s, e;
		cin >> s >> e;
		--s;
		--e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	
	vector<bool> visit(N, false);
	queue<int> q;
	q.push(0);
	visit[0] = true;
	while (!q.empty())
	{
		int curV = q.front();
		q.pop();

		for (int i = 0; i < graph[curV].size(); ++i)
		{
			if (visit[graph[curV][i]]) continue;

			visit[graph[curV][i]] = true;
			vertex[graph[curV][i]] = curV;
			q.push(graph[curV][i]);
		}
	}

	for (int i = 1; i < vertex.size(); ++i)
	{
		cout << vertex[i] + 1 << "\n";
	}
	return 0;
}
