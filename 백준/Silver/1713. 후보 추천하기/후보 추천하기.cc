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
	cin.tie(NULL);

	int N;
	cin >> N;

	int cnt;
	cin >> cnt;

	vector<int> numbers(cnt);
	vector<int> answer;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> numbers[i];
	}
	multiset<pair<int, int>> frame;
	map<int, int> info;
	for (int i = 0; i < numbers.size(); ++i)
	{
		int val = numbers[i];
		info[val]++;

		if (info[val] > 1)
		{
			info[val]++;
			continue;
		}

		if (frame.size() == N)
		{
			map<int, vector<int>> tmp;
			for (const auto& each : frame)
			{
				tmp[info[each.second]].push_back(each.second);
			}
			info[tmp.begin()->second.front()] = 0;
			for (auto iter = frame.begin(); iter != frame.end();)
			{
				if (iter->second == tmp.begin()->second.front())
				{
					iter = frame.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}

		if (info[val] == 1)
		{
			frame.insert({ i,val });
		}
	}

	for (const auto& each : frame)
	{
		answer.push_back(each.second);
	}

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}
	return 0;
}

