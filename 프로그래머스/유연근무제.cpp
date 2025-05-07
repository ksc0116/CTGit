// https://school.programmers.co.kr/learn/courses/30/lessons/388351
// 시간 복잡도 : O(N)

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday)
{
	int answer = 0;

	for (int i = 0; i < timelogs.size(); ++i)
	{
		int h = schedules[i] / 100;
		int m = ((schedules[i] % 100) + 10);
		if (m > 59)
		{
			h++;
			m = m - 60;
		}

		int maxVal = h * 100 + m;
		bool flag = false;
		int tempStart = startday;

		for (int j = 0; j < timelogs[i].size(); ++j)
		{
			if (tempStart > 7)
			{
				tempStart = 1;
			}
			if (tempStart == 6 || tempStart == 7)
			{
				tempStart++;
				continue;
			}

			if (timelogs[i][j] > maxVal)
			{
				flag = true;
				break;
			}
			tempStart++;
		}

		if (!flag)
		{
			answer++;
		}
	}

	return answer;
}