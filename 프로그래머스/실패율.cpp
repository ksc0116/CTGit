// https://school.programmers.co.kr/learn/courses/30/lessons/42889
// 시간 복잡도 : O(M + NlogN)


#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool Cmp(const pair<int, float>& lhs, const pair<int, float>& rhs)
{
	if (lhs.second == rhs.second)
		return lhs.first < rhs.first;

	return lhs.second > rhs.second;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	map<int, int> cntMap;
	for (int i = 0; i < stages.size(); ++i)
	{
		cntMap[stages[i]]++;
	}

	int remainPeople = stages.size();
	vector<pair<int, float>> failRatio;
	for (int i = 1; i < N + 1; ++i)
	{
		int curStage = i;

		auto iter = cntMap.find(curStage);
		if (iter == cntMap.end())
		{
			failRatio.push_back({ curStage,0.f });
		}
		else
		{
			failRatio.push_back({ curStage, (float)cntMap[curStage] / (float)remainPeople });
			remainPeople -= cntMap[curStage];
		}
	}

	sort(failRatio.begin(), failRatio.end(), Cmp);

	for (int i = 0; i < failRatio.size(); ++i)
	{
		answer.push_back(failRatio[i].first);
	}
	return answer;
}