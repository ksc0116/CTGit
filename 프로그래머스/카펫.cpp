// https://school.programmers.co.kr/learn/courses/30/lessons/42842
// 시간 복잡도 : O(sqrt(N + M))

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow)
{
	vector<int> answer;

	int totalCnt = brown + yellow;

	for (int i = 3; i <= sqrt(totalCnt); ++i)
	{
		if (totalCnt % i == 0)
		{
			int col = totalCnt / i;
			if (col >= i)
			{
				int yCol = col - 2;
				int yRow = i - 2;
				int yCnt = yCol * yRow;
				if (yCnt == yellow)
				{
					return { col, i };
				}
			}
		}
	}

	return answer;
}