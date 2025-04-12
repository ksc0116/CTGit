// https://school.programmers.co.kr/learn/courses/30/lessons/42861
// 시간 복잡도 : O(NlogN)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int Find(int num)
{
	if (v[num] == -1) return num;

	return v[num] = Find(v[num]);
}

bool isCycle(int num1, int num2)
{
	return Find(num1) == Find(num2);
}



void Union(int num1, int num2)
{
	int p1 = Find(num1);
	int p2 = Find(num2);

	if (p1 != p2)
	{
		v[p2] = p1;
	}
}

int solution(int n, vector<vector<int>> costs)
{
	sort(costs.begin(), costs.end(),
		[](const vector<int>& lhs, const vector<int>& rhs) {return lhs[2] < rhs[2]; });

	v.resize(n, -1);


	int totalCost = 0;

	for (int i = 0; i < costs.size(); ++i)
	{
		int num1 = costs[i][0];
		int num2 = costs[i][1];
		int cost = costs[i][2];

		if (!isCycle(num1, num2))
		{
			Union(num1, num2);
			totalCost += cost;
		}
	}

	return totalCost;
}