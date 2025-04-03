// https://school.programmers.co.kr/learn/courses/30/lessons/49994
// 시간 복잡도 : O(N)


#include <string>
#include <set>
using namespace std;

int solution(string dirs)
{
	int answer = 0;
	set<pair<pair<int, int>, pair<int, int>>> ansSet;
	// y, x
	pair<int, int> curPos = { 0,0 };

	for (const auto& dir : dirs)
	{
		int curX = curPos.second;
		int curY = curPos.first;
		int n_x = curX;
		int n_y = curY;
		if (dir == 'U')
		{
			n_y = curY + 1;
		}
		else if (dir == 'D')
		{
			n_y = curY - 1;
		}
		else if (dir == 'R')
		{
			n_x = curX + 1;
		}
		else
		{
			n_x = curX - 1;
		}

		if (n_x < -5 || n_x > 5 || n_y < -5 || n_y > 5) continue;

		ansSet.insert({ {curY,curX},{n_y,n_x} });
		ansSet.insert({ {n_y,n_x},{curY,curX} });
		curPos = { n_y, n_x };
	}

	return ansSet.size() / 2;
}