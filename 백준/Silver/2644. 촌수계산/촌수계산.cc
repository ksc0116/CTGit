#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;



void DFS(int depth, const vector<vector<int>>& graph, int curV, int targetV, vector<bool>& visit,int& answer)
{
	if (visit[curV]) return;

	visit[curV] = true;
	if (curV == targetV)
	{
		answer = depth;
		return;
	}

	for (int i = 0; i < graph[curV].size(); ++i)
	{
		DFS(depth + 1, graph, graph[curV][i], targetV, visit, answer);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int p1, p2;
	cin >> p1 >> p2;
	int m;
	cin >> m;

	vector<vector<int>> graph(n);
	vector<bool> visit(n,false);
	for (int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;
		--s;
		--e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	
	int answer = -1;

	int depth = 0;
	DFS(depth, graph, --p1, --p2, visit, answer);
	cout << answer << "\n";

	return 0;
}

