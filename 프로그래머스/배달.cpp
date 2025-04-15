// https://school.programmers.co.kr/learn/courses/30/lessons/12978
// 시간 복잡도 : O((N + E)logN)

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;
void Func(int start)
{
	// 거리 , 노드 번호
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int curDist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[curNode].size(); ++i)
		{
			int nextDist = curDist + graph[curNode][i].second;
			int nextNode = graph[curNode][i].first;

			if (dist[nextNode] > nextDist)
			{
				dist[nextNode] = nextDist;
				pq.push({ -nextDist, nextNode });
			}
		}
	}
}

int solution(int N, vector<vector<int> > road, int K)
{
	int answer = 0;

	graph.resize(N + 1);
	dist.resize(N + 1, INT_MAX);

	for (int i = 0; i < road.size(); ++i)
	{
		int s = road[i][0];
		int e = road[i][1];
		int cost = road[i][2];

		graph[s].push_back({ e,cost });
		graph[e].push_back({ s,cost });
	}

	// 1번에서 각 노드까지의 최단 경로 구하기
	Func(1);

	for (int i = 1; i < dist.size(); ++i)
	{
		if (dist[i] <= K) answer++;
	}

	return answer;
}