// https://school.programmers.co.kr/learn/courses/30/lessons/42579
// 시간 복잡도 : O(NlogN)

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
struct Cmp
{
	bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const
	{
		if (lhs.first != rhs.first)
			return lhs.first > rhs.first;

		return lhs.second < rhs.second;
	}
};
struct Cmp2
{
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const
	{
		if (lhs.first != rhs.first)
			return lhs.first > rhs.first;

		return lhs.second < rhs.second;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;

	map<string, int> playInfo;
	unordered_map<string, set<pair<int, int>, Cmp2>> singInfo;
	for (int i = 0; i < plays.size(); ++i)
	{
		playInfo[genres[i]] += plays[i];
		singInfo[genres[i]].insert({ plays[i], i });
	}
	// 많이 재생된 장르가 맨 앞에 있음
	set<pair<int, string>, Cmp> manyPlays;
	for (const auto& each : playInfo)
	{
		manyPlays.insert({ each.second,each.first });
	}

	for (const auto& each : manyPlays)
	{
		string cur = each.second;
		auto iter = singInfo[cur].begin();
		answer.push_back(iter->second);
		++iter;
		if (iter != singInfo[cur].end())
		{
			answer.push_back(iter->second);
		}
	}



	return answer;
}