// https://school.programmers.co.kr/learn/courses/30/lessons/43105
// 시간 복잡도 : O(N^2)

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	int answer = 0;

	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));


	for (int i = 0; i < triangle.size(); ++i)
	{
		dp[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
	}

	for (int i = triangle.size() - 2; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}

	return dp[0][0];
}