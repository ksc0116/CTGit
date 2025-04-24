// https://school.programmers.co.kr/learn/courses/30/lessons/42746
// 시간 복잡도 : O(NlogN)

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Cmp(const string& lhs, const string& rhs)
{
	return (rhs + lhs) > (lhs + rhs);
}

string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> temp;

	for (int i = 0; i < numbers.size(); ++i)
	{
		temp.push_back(to_string(numbers[i]));
	}

	sort(temp.begin(), temp.end(), Cmp);

	for (int i = 0; i < temp.size(); ++i)
	{
		answer += temp[i];
	}

	return answer[0] == '0' ? "0" : answer;
}