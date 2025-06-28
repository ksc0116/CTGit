#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int, int>> house;
int answer = INT_MAX;
int N, M;

int CheckMin(const vector<pair<int, int>>& select)
{
	int totalDist = 0;
	for (int i = 0; i < house.size(); ++i)
	{
		int dist = INT_MAX;
		auto housePos = house[i];
		for (int j = 0; j < select.size(); ++j)
		{
			auto selPos = select[j];
			dist = min(dist, abs(housePos.first - selPos.first) + abs(housePos.second - selPos.second));
		}
		totalDist += dist;
	}
	return totalDist;
}

void GetComb(int index, const vector<pair<int, int>>& info, int r, vector<pair<int, int>>& select)
{
	if (select.size() == r)
	{
		answer = min(answer, CheckMin(select));
	}
	
	if (index == info.size())
		return;

	for (int i = index; i < info.size(); ++i)
	{
		select.push_back(info[i]);
		GetComb(i + 1, info, r, select);
		select.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<pair<int, int>> info;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int num = 0;
			cin >> num;
			if (num == 2)
			{
				info.push_back({ i,j });
			}
			else if(num == 1)
			{
				house.push_back({ i,j });
			}
		}
	}
	vector<pair<int, int>> select;
	GetComb(0,info, M, select);

	cout << answer << endl;
	return 0;
}

