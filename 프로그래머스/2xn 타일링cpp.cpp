// https://school.programmers.co.kr/learn/courses/30/lessons/12900
// 시간 복잡도 : O(N)

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 0;

	vector<int> dp(60001, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}

	return dp[n];
}