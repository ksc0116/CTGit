#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>

// 시간 복잡도 : E + V


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	vector<bool> visit(N,false);
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[--s].push_back(--e);
		graph[e].push_back(s);
	}

	int answer = 0;
	visit[0] = true;
	queue<int> q;
	q.push(0);

	while (!q.empty())
	{
		int curV = q.front();
		q.pop();
		
		for (int i = 0; i < graph[curV].size(); ++i)
		{
			if (!visit[graph[curV][i]])
			{
				q.push(graph[curV][i]);
				visit[graph[curV][i]] = true;
				answer++;
			}
		}
	}


	cout << answer << endl;

	return 0;
}
