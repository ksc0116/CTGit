// https://school.programmers.co.kr/learn/courses/30/lessons/86971
// 시간 복잡도 : O(N^2)

#include <string>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

vector<vector<int>> graph;

void Check(int node, vector<bool>& visited, int cutEdge1, int cutEdge2, int& cnt)
{
	visited[node] = true;
	cnt++;
	for (int i = 0; i < graph[node].size(); ++i)
	{
		if (visited[graph[node][i]]) continue;
		if (node == cutEdge1 && graph[node][i] == cutEdge2
			|| node == cutEdge2 && graph[node][i] == cutEdge1) continue;

		Check(graph[node][i], visited, cutEdge1, cutEdge2, cnt);
	}
}

int solution(int n, vector<vector<int>> wires)
{
	int answer = INT_MAX;

	graph.resize(n + 1);

	for (int i = 0; i < wires.size(); ++i)
	{
		int node1 = wires[i][0];
		int node2 = wires[i][1];
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	for (int i = 0; i < wires.size(); ++i)
	{
		int node1 = wires[i][0];
		int node2 = wires[i][1];
		vector<bool> visited(n + 1, false);
		int cnt = 0;
		Check(1, visited, node1, node2, cnt);
		answer = min(answer, abs((n - cnt) - cnt));
	}

	return answer;
}