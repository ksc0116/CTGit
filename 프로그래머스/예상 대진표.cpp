// https://school.programmers.co.kr/learn/courses/30/lessons/12985
// O(log^2N)

#include <set>
using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	set<int> boardSet;
	boardSet.insert(-1);
	for (int i = 1; i <= n; ++i)
	{
		boardSet.insert(i);
	}
	int deleted = -1;
	auto iter = next(boardSet.begin());
	int cnt = 1;
	while (true)
	{
		if (iter == boardSet.end())
		{
			iter = next(boardSet.begin());
			cnt++;
		}
		if (deleted != -1)
		{
			boardSet.erase(boardSet.find(deleted));
			deleted = -1;
		}
		int num1 = *iter;
		iter = next(iter);
		int num2 = *iter;
		if (num1 != a && num1 != b)
		{
			deleted = (num1);
			iter = next(iter);
			continue;
		}
		else if (num2 != a && num2 != b)
		{
			deleted = (num2);
			iter = next(iter);
			continue;
		}

		if ((num1 == a && num2 == b) || (num1 == b && num2 == a))
		{
			return cnt;
		}
	}

	return answer;
}