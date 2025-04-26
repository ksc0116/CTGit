// https://school.programmers.co.kr/learn/courses/30/lessons/132265
// 시간 복잡도 : O(N)

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping)
{
	int answer = 0;

	unordered_map<int, int> aMap;
	unordered_map<int, int> bMap;

	for (int i = 0; i < topping.size(); ++i)
	{
		aMap[topping[i]]++;
	}

	for (int i = 0; i < topping.size(); ++i)
	{
		aMap[topping[i]]--;
		bMap[topping[i]]++;

		if (aMap[topping[i]] <= 0)
		{
			aMap.erase(aMap.find(topping[i]));
		}

		if (aMap.size() == bMap.size())
		{
			answer++;
		}
	}

	return answer;
}