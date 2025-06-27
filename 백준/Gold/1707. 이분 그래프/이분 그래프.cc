#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

constexpr int NONE = -1;
constexpr int BLACK = 0;
constexpr int WHITE = 1;

vector<string> answer;

void DFS(const vector<vector<int>>& graph,int curV, int curColor, vector<int>& color)
{
	for (int i = 0; i < graph[curV].size(); ++i)
	{
		int nextV = graph[curV][i];
		if (color[nextV] != NONE) continue;
		
		color[nextV] = curColor == BLACK ? WHITE : BLACK;
		DFS(graph, graph[curV][i], curColor == BLACK? WHITE : BLACK, color);
	}
}

void Check(const vector<vector<int>>& graph, const vector<int>& color)
{
	for (int i = 0; i < graph.size(); ++i)
	{
		int curColor = color[i];
		for (int j = 0; j < graph[i].size(); ++j)
		{
			int nextColor = color[graph[i][j]];
			if (curColor == nextColor)
			{
				answer.push_back("NO");
				return;
			}
		}
	}
	answer.push_back("YES");
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int K;
	cin >> K;
	while (K--)
	{
		int V, E;
		cin >> V >> E;

		vector<vector<int>> graph(V);
		vector<int> color(V, NONE);
		
		for (int i = 0; i < E; ++i)
		{
			int s, e;
			cin >> s >> e;
			graph[s - 1].push_back(e - 1);
			graph[e - 1].push_back(s - 1);
		}
		for (int i = 0; i < V; ++i)
		{
			if (color[i] != NONE) continue;
			color[i] = BLACK;
			DFS(graph, i, BLACK, color);
		}
		Check(graph, color);
	}
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}
	return 0;
}