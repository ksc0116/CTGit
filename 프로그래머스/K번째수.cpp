// https://school.programmers.co.kr/learn/courses/30/lessons/42748
// 시간 복잡도 : O(M * NlogN)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;

	for (int i = 0; i < commands.size(); ++i)
	{
		vector<int> tempVec = array;
		int s = commands[i][0] - 1;
		int e = commands[i][1] - 1;
		int k = commands[i][2] - 1;

		sort(tempVec.begin() + s, tempVec.end() - (tempVec.size() - 1 - e));
		answer.push_back(tempVec[s + k]);
	}

	return answer;
}