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

void DFS(int curV, const vector<vector<int>>& graph, vector<bool>& visited, int& cnt)
{
	visited[curV] = true;
	cnt++;
	for (int next : graph[curV])
	{
		if (!visited[next]) 
		{
			DFS(next, graph, visited, cnt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		--A;
		--B;
		graph[B].push_back(A);
	}

	vector<int> result(N, 0);
	int maxCnt = 0;

	for (int i = 0; i < N; i++)
	{
		vector<bool> visited(N, false);
		int cnt = 0;
		DFS(i, graph, visited, cnt);
		result[i] = cnt;
		maxCnt = max(maxCnt, cnt);
	}
	for (int i = 0; i < N; i++)
	{
		if (result[i] == maxCnt) 
		{
			cout << i + 1 << " ";
		}
	}
	return 0;
}

