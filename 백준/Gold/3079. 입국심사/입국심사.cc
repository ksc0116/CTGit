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

bool Check(const vector<long long>& time, long long mid, long long M)
{
	long long sum = 0;
	for (int i = 0; i < time.size(); ++i)
	{
		sum += (mid / time[i]);
		if (sum >= M)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, M;
	cin >> N >> M;

	vector<long long> time(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> time[i];
	}

	long long left = 1;
	long long right = 1e18;

	while (left < right)
	{
		long long mid = (left + right) / 2;

		if (Check(time, mid, M))
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
