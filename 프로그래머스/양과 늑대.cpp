// https://school.programmers.co.kr/learn/courses/30/lessons/92343
// 시간 복잡도 : O(N^2)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
vector<bool> visited;
vector<vector<int>> tree;

void DFS(vector<int> v, const vector<int>& info)
{
	int sheepCnt = 0;
	int wolfCnt = 0;

	for (auto& cur : v)
	{
		if (info[cur] == 0) sheepCnt++;
		else wolfCnt++;
	}

	if (sheepCnt <= wolfCnt) return;

	answer = max(answer, sheepCnt);

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < tree[v[i]].size(); ++j)
		{
			if (visited[tree[v[i]][j]]) continue;

			visited[tree[v[i]][j]] = true;
			v.push_back(tree[v[i]][j]);
			DFS(v, info);
			v.pop_back();
			visited[tree[v[i]][j]] = false;
		}
	}
}
int solution(vector<int> info, vector<vector<int>> edges)
{
	visited.resize(info.size());
	tree.resize(info.size());
	for (int i = 0; i < edges.size(); ++i)
	{
		int node1 = edges[i][0];
		int node2 = edges[i][1];
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	visited[0] = true;
	DFS({ 0 }, info);

	return answer;
}