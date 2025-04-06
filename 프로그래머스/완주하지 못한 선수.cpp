// https://school.programmers.co.kr/learn/courses/30/lessons/42576
// 시간 복잡도 : O(N)

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	unordered_map<string, int> infoMap;

	for (int i = 0; i < participant.size(); ++i)
	{
		infoMap[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); ++i)
	{
		infoMap[completion[i]]--;
		if (infoMap[completion[i]] == 0)
			infoMap.erase(completion[i]);
	}

	return infoMap.begin()->first;
}