// https://school.programmers.co.kr/learn/courses/30/lessons/42840
// 시간 복잡도 : O(N)

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> answers)
{
	vector<int> answer;

	vector<vector<int>> nums =
	{
		{1,2,3,4,5},
		{2,1,2,3,2,4,2,5},
		{3,3,1,1,2,2,4,4,5,5}
	};
	int maxVal = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		vector<int> cur = nums[i];
		int cnt = 0;
		for (int j = 0; j < answers.size(); ++j)
		{
			if (answers[j] == cur[j % cur.size()])
			{
				cnt++;
			}
		}
		if (cnt == 0) continue;
		if (maxVal == cnt)
		{
			maxVal = cnt;
			answer.push_back(i + 1);
		}
		else if (maxVal < cnt)
		{
			answer.clear();
			maxVal = cnt;
			answer.push_back(i + 1);
		}
	}

	return answer;
}