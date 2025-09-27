#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

// 시간 복잡도 : N + M
int curDepth = 1;
void DFS(vector<int>& answer, vector<set<int>>& graph, int curV)
{
	if (answer[curV] != 0) return;

	answer[curV] = curDepth++;

	for (const auto& each : graph[curV])
	{
		DFS(answer, graph, each);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	vector<set<int>> graph(N + 1);
	vector<int> answer(N + 1,0);

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].insert(e);
		graph[e].insert(s);
	}
	
	DFS(answer, graph, R);

	for (int i = 1; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}
	return 0;
}