// https://school.programmers.co.kr/learn/courses/30/lessons/131127
// 시간 복잡도 :O(N)

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
	int answer = 0;

	for (int i = 0; i <= discount.size() - 10; ++i)
	{
		unordered_map<string, int> info;
		for (int j = i; j < i + 10; ++j)
		{
			info[discount[j]]++;
		}

		bool flag = true;
		for (int j = 0; j < want.size(); ++j)
		{
			if (info[want[j]] < number[j])
			{
				flag = false;
			}
		}
		if (flag)
			answer++;
	}

	return answer;
}