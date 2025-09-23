#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

// 시간 복잡도 : cnt * NlogN

void DFS(const vector<vector<pair<int,int>>>& graph, vector<int>& dist, int curV, int weight)
{
	dist[curV] = weight;


	for (int i = 0; i < graph[curV].size(); ++i)
	{
		if (dist[graph[curV][i].first] != -1) continue;

		DFS(graph, dist, graph[curV][i].first, weight + graph[curV][i].second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> graph(n);
	vector<vector<int>> leafGraph(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int s, e, w;
		cin >> s >> e >> w;
		--s;
		--e;
		graph[s].push_back({ e,w });
		graph[e].push_back({ s,w });
	}
	vector<int> dist(n, -1);
	DFS(graph, dist, 0, 0);
	int far1 = max_element(dist.begin(), dist.end()) - dist.begin();

	dist.clear();
	dist.resize(n, -1);
	DFS(graph, dist, far1, 0);
	cout << *max_element(dist.begin(), dist.end()) << "\n";
	return 0;
}

