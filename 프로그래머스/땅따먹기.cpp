// https://school.programmers.co.kr/learn/courses/30/lessons/12913
// 시간 복잡도 : O(N)

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	vector<vector<int>> dp(land.size(), vector<int>(4, 0));
	dp = land;
	for (int i = 1; i < land.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (j != k)
				{
					dp[i][j] = max(dp[i - 1][k] + land[i][j], dp[i][j]);
				}
			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		answer = max(dp[land.size() - 1][i], answer);
	}
	return answer;
}