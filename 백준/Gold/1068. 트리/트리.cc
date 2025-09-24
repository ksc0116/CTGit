#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

// 시간 복잡도 : 

void RemoveNode(vector<bool>& remove, vector<vector<int>>& graph, int curV)
{
	remove[curV] = true;

	for (int i = 0; i < graph[curV].size(); ++i)
	{
		if (remove[graph[curV][i]]) continue;

		RemoveNode(remove, graph, graph[curV][i]);
	}
}

void DFS(const vector<bool>& remove, vector<bool>& visit, vector<vector<int>>& graph, int curV, int& answer)
{
	if (remove[curV] || visit[curV]) return;

	visit[curV] = true;

	bool hasChild = false;
	for (int i = 0; i < graph[curV].size(); ++i)
	{
		if (visit[graph[curV][i]] || remove[graph[curV][i]]) continue;
		hasChild = true;

		DFS(remove,visit, graph, graph[curV][i], answer);
	}

	if (!hasChild)
	{
		answer++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int root = 0;

	vector<vector<int>> graph(N);
	for (int i = 0; i < N; ++i)
	{
		int val = 0;
		cin >> val;
		if (val == -1)
		{
			graph[i].push_back(i);
			root = i;
		}
		else
		{
			graph[val].push_back(i);
		}
	}

	int removeNode;
	cin >> removeNode;

	vector<bool> remove(N);
	RemoveNode(remove, graph, removeNode);

	int answer = 0;
	vector<bool> visit(N);
	DFS(remove,visit, graph, root, answer);
	cout << answer << "\n";

	return 0;
}

