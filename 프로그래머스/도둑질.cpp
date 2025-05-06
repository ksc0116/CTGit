// https://school.programmers.co.kr/learn/courses/30/lessons/42897
// 시간 복잡도 : O(N)

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money)
{
	int answer = 0;

	vector<int> dp1(money.size(), 0);
	vector<int> dp2(money.size(), 0);

	dp1[0] = money[0];
	dp1[1] = dp1[0];

	dp2[1] = money[1];

	// 처음 집을 도둑질 한 경우
	for (int i = 2; i < money.size() - 1; ++i)
	{
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
	}
	dp1[money.size() - 1] = dp1[money.size() - 2];

	// 두번째 집을 도둑질 한 경우
	for (int i = 2; i < money.size(); ++i)
	{
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}

	return max(dp1[money.size() - 1], dp2[money.size() - 1]);
}