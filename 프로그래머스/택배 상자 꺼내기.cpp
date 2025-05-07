// https://school.programmers.co.kr/learn/courses/30/lessons/389478
// 시간 복잡도 : O(N * M)

#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num)
{
	int answer = 0;
	vector<vector<int>> box;

	int row = 0;
	int cnt = 1;
	while (n >= cnt)
	{
		box.push_back(vector<int>(w, 0));
		if (row % 2 == 0)
		{
			// 짝수 행
			for (int i = 0; i < w; ++i)
			{
				if (cnt <= n)
				{
					box[row][i] = cnt;
					cnt++;
				}
			}
		}
		else
		{
			// 홀수 행
			for (int i = w - 1; i >= 0; --i)
			{
				if (cnt <= n)
				{
					box[row][i] = cnt;
					cnt++;
				}
			}
		}
		row++;
	}

	int findRow = 0;
	int findCol = 0;

	for (int i = 0; i < box.size(); ++i)
	{
		for (int j = 0; j < box[0].size(); ++j)
		{
			if (box[i][j] == num)
			{
				findRow = i;
				findCol = j;
			}
		}
	}
	for (int i = findRow; i < box.size(); ++i)
	{
		if (box[i][findCol] != 0)
		{
			answer++;
		}
	}
	return answer;
}