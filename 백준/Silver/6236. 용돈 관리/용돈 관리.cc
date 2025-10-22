#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <limits.h>
using namespace std;

bool Check(const vector<int>& cost, int mid, int M)
{
	int cnt = 1;
	int curMoney = mid;
	for (int i = 0; i < cost.size(); ++i)
	{
		int curCost = cost[i];
		if (mid < curCost) return false;

		if (curCost <= curMoney)
		{
			curMoney -= curCost;
		}
		else
		{
			cnt++;
			curMoney = mid;
			curMoney -= curCost;
		}
	}

	return cnt <= M;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> cost(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cost[i];
	}

	int left = 1;
	int right = N * 10000;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (Check(cost,mid,M))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << left << "\n";
	return 0;
}
