// https://school.programmers.co.kr/learn/courses/30/lessons/64065
// 시간 복잡도 : O(NlogN)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int counts[100001] = {};


bool Cmp(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
	return lhs.first > rhs.first;
}

vector<int> solution(string s)
{
	vector<int> answer;

	string numStr;
	for (auto ch : s)
	{
		if (isdigit(ch))
		{
			numStr += ch;
		}
		else
		{
			if (!numStr.empty())
			{
				counts[stoi(numStr)]++;
				numStr.clear();
			}
		}
	}
	vector<pair<int, int>> pairVec;
	for (int i = 1; i <= 100000; ++i)
	{
		if (counts[i] > 0)
		{
			pairVec.push_back({ counts[i],i });
		}
	}

	sort(pairVec.begin(), pairVec.end(), Cmp);

	for (int i = 0; i < pairVec.size(); ++i)
	{
		answer.push_back(pairVec[i].second);
	}

	return answer;
}