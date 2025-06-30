#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <limits.h>

using namespace std;
int N, M;
bool flag;

void DFS(int v, const vector<vector<int>>& graph, int depth, vector<bool>& visit)
{
	if (flag)
	{
		return;
	}

	if (depth == 4)
	{
		flag = true;
		return;
	}
	
	for (int i = 0; i < graph[v].size(); ++i)
	{
		int next = graph[v][i];
		if (visit[next]) continue;

		visit[next] = true;
		DFS(next, graph, depth + 1, visit);
		visit[next] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<int>> graph(N);
	for (int i = 0; i < M; ++i)
	{
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	for (int i = 0; i < N; ++i)
	{
		vector<bool> visit(N, false);
		visit[i] = true;
		DFS(i, graph, 0, visit);
	}
	
	if (flag)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}

	return 0;
}
