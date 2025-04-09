// https://school.programmers.co.kr/learn/courses/30/lessons/72411
// 시간 복잡도 : O(N * 2^M) 

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> orderCntMap;

void comb(const string& src, string dst, int curDepth, int depth)
{
	if (dst.size() == depth)
	{
		orderCntMap[dst]++;
		return;
	}

	for (int i = curDepth; i < src.size(); ++i)
	{
		comb(src, dst + src[i], ++curDepth, depth);
	}
}

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	// 메뉴 조합별로 몇개의 주문이 있었는지
	for (int i = 0; i < orders.size(); ++i)
	{
		string curOrder = orders[i];
		sort(curOrder.begin(), curOrder.end());
		for (int j = 0; j < course.size(); ++j)
		{
			if (curOrder.size() < course[j])
			{
				continue;
			}
			comb(curOrder, "", 0, course[j]);
		}
	}

	unordered_map<int, vector<pair<string, int>>> manyOrderMap;

	for (const auto& each : orderCntMap)
	{
		auto& curVec = manyOrderMap[each.first.size()];
		if (curVec.empty())
		{
			curVec.push_back({ each.first,each.second });
		}
		else
		{
			int cnt = curVec[0].second;
			if (cnt < each.second)
			{
				curVec.clear();
				curVec.push_back({ each.first, each.second });
			}
			else if (cnt == each.second)
			{
				curVec.push_back({ each.first, each.second });
			}
		}
	}

	for (const auto& each : manyOrderMap)
	{
		for (int i = 0; i < each.second.size(); ++i)
		{
			if (each.second[i].second >= 2)
				answer.push_back(each.second[i].first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}