#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> fruits(N);

	for (int i = 0; i < N; ++i)
	{
		int val = 0;
		cin >> val;
		fruits[i] = val;
	}

	int left = 0;
	int answer = 0;
	unordered_map<int, int> cnt;
	for (int right = 0; right < N; ++right)
	{
		cnt[fruits[right]]++;

		while (cnt.size() > 2)
		{
			cnt[fruits[left]]--;
			if (cnt[fruits[left]] == 0)
			{
				cnt.erase(fruits[left]);
			}
			left++;
		}

		answer = max(answer, right - left + 1);
	}

	cout << answer << "\n";

	return 0;
}

