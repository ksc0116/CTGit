// https://school.programmers.co.kr/learn/courses/30/lessons/12915
// 시간 복잡도 : O(NSlogN)

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool Cmp(const string& lhs, const string& rhs)
{
	if (lhs[N] == rhs[N])
	{
		return lhs < rhs;
	}
	else
	{
		return lhs[N] < rhs[N];
	}
}

vector<string> solution(vector<string> strings, int n)
{
	N = n;
	sort(strings.begin(), strings.end(), Cmp);

	return strings;
}