// https://school.programmers.co.kr/learn/courses/30/lessons/138476
// 시간 복잡도 : O(NlogN)

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine)
{
	int answer = 0;

	unordered_map<int, int> info;
	vector<int> count;

	for (int i = 0; i < tangerine.size(); ++i)
	{
		info[tangerine[i]]++;
	}

	for (auto each : info)
	{
		count.push_back(each.second);
	}

	sort(count.begin(), count.end(), greater<>());

	for (int i = 0; i < count.size(); ++i)
	{
		k -= count[i];
		answer++;
		if (k <= 0) break;
	}

	return answer;
}