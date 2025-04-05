// https://school.programmers.co.kr/learn/courses/30/lessons/159994
// 시간 복잡도 : O(N + M)

#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
	string answer = "";

	queue<string> c1q;
	queue<string> c2q;
	queue<string> gq;

	for (int i = 0; i < cards1.size(); ++i)
	{
		c1q.push(cards1[i]);
	}
	for (int i = 0; i < cards2.size(); ++i)
	{
		c2q.push(cards2[i]);
	}
	for (int i = 0; i < goal.size(); ++i)
	{
		gq.push(goal[i]);
	}

	while (!gq.empty())
	{
		string c1 = "";
		string c2 = "";
		string g = "";
		if (!c1q.empty())
		{
			c1 = c1q.front();
		}
		if (!c2q.empty())
		{
			c2 = c2q.front();
		}
		if (!gq.empty())
		{
			g = gq.front();
		}

		if (c1 == g)
		{
			c1q.pop();
			gq.pop();
			continue;
		}
		if (c2 == g)
		{
			c2q.pop();
			gq.pop();
			continue;
		}

		return "No";
	}

	return "Yes";
}