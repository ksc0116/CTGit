#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int dist[100001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(dist, dist + 100001, -1);

	int N, K;
	cin >> N >> K;
	
	queue<int> q;
	q.push(N);
	dist[N] = 0;

	while (!q.empty())
	{
		int curNum = q.front();
		q.pop();

		int curDist = dist[curNum];

		// -1
		if (curNum - 1 >= 0 && dist[curNum - 1] == -1)
		{
			q.push(curNum - 1);
			dist[curNum - 1] = curDist + 1;
		}
		
		// +1
		if (curNum + 1 < 100001 && dist[curNum + 1] == -1)
		{
			q.push(curNum + 1);
			dist[curNum + 1] = curDist + 1;
		}
		
		// *2
		if (curNum * 2 < 100001 && dist[curNum*2] == -1)
		{
			q.push(curNum*2);
			dist[curNum*2] = curDist + 1;
		}
	}
	int answer = dist[K];
	cout << answer << endl;
	
	return 0;
}