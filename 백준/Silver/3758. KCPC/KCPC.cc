#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <limits.h>
using namespace std;

struct TeamInfo
{
	int id;
	int totalScore;
	int time;
	int cnt;
};

bool Comp(const TeamInfo& lhs, const TeamInfo& rhs)
{
	if (lhs.totalScore == rhs.totalScore)
	{
		if (lhs.cnt == rhs.cnt)
		{
			return lhs.time > rhs.time;
		}
		else
		{
			return lhs.cnt > rhs.cnt;
		}
	}
	
	return lhs.totalScore < rhs.totalScore;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	vector<int> finalAnswer;
	while (T--)
	{
		int n, k, t, m;
		cin >> n >> k >> t >> m;

		unordered_map<int, map<int, int>> teamInfo;
		unordered_map<int, int> teamCnt;
		unordered_map<int, int> teamTotalScroe;
		unordered_map<int, int> teamTime;

		for (int k = 0; k < m; ++k)
		{
			int i, j, s;
			cin >> i >> j >> s;

			teamCnt[i]++;
			teamTime[i] = k;

			if (teamInfo[i].find(j) == teamInfo[i].end())
			{
				teamInfo[i][j] = s;
				teamTotalScroe[i] += s;
			}
			else
			{
				if (teamInfo[i][j] < s)
				{
					teamTotalScroe[i] -= teamInfo[i][j];
					teamInfo[i][j] = s;
					teamTotalScroe[i] += s;
				}
			}
		}

		vector<TeamInfo> infoVec;
		for (const auto& each : teamInfo)
		{
			int id = each.first;
			TeamInfo info;
			info.id = id;
			info.cnt = teamCnt[id];
			info.time = teamTime[id];
			info.totalScore = teamTotalScroe[id];
			infoVec.push_back(info);
		}
		sort(infoVec.begin(), infoVec.end(),Comp);

		for (int k = 0; k < infoVec.size(); ++k)
		{
			if (infoVec[k].id == t)
			{
				finalAnswer.push_back(n - k);
				break;
			}
		}
	}

	for (int i = 0; i < finalAnswer.size(); ++i)
	{
		cout << finalAnswer[i] << "\n";
	}

	return 0;
}
