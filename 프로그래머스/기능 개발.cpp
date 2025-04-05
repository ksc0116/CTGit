// https://school.programmers.co.kr/learn/courses/30/lessons/42586
// 시간 복잡도 : O(N)


#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < speeds.size(); ++i)
	{
		q.push(ceil((float)(100 - progresses[i]) / (float)speeds[i]));
	}


	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int cnt = 1;
		while (!q.empty() && q.front() <= cur)
		{
			q.pop();
			cnt++;
		}
		answer.push_back(cnt);
	}

	return answer;
}