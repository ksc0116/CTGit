#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, w, L;
	cin >> n >> w >> L;

	queue<int> weights;
	for (int i = 0; i < n; ++i)
	{
		int weight = 0;
		cin >> weight;
		weights.push(weight);
	}
	
	int totalWeight = 0;
	int sec = 1;
	queue<pair<int,int>> exitQ;
	while (!weights.empty())
	{
		// 나가는 대기 큐 확인
		if (!exitQ.empty() && (exitQ.front().first == sec))
		{
			totalWeight -= exitQ.front().second;
			exitQ.pop();
		}

		// 다리에 진입이 가능한 지 확인
		if (totalWeight + weights.front() > L)
		{
			sec++;
			continue;
		}

		exitQ.push({sec + w, weights.front()});
		totalWeight += weights.front();
		weights.pop();
		sec++;
	}

	int answer = 0;
	while (!exitQ.empty())
	{
		answer = exitQ.front().first;
		exitQ.pop();
	}
	cout << answer << endl;
	return 0;
}
