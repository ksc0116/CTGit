// https://school.programmers.co.kr/learn/courses/30/lessons/12949
// 시간 복잡도 O(N^3)

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));
	// 1 4     3 3      15 15
	// 3 2     3 3      15 15
	// 4 1              15 15

	for (int i = 0; i < arr1.size(); ++i)
	{
		for (int j = 0; j < arr2[0].size(); ++j)
		{
			for (int k = 0; k < arr2.size(); ++k)
			{
				answer[i][j] += (arr1[i][k] * arr2[k][j]);
			}
		}
	}

	return answer;
}