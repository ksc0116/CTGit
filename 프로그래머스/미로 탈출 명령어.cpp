// https://school.programmers.co.kr/learn/courses/30/lessons/150365
// 시간 복잡도 : O(4^N)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dx[] = { 0,-1,1,0 };
int dy[] = { 1,0,0,-1 };
char dir[] = { 'd','l','r','u' };
int row, col, maxDepth, endX, endY;
bool isFinish = false;

string answer;

void DFS(int y, int x, int depth, string str)
{
	if (depth == maxDepth)
	{
		if (y == endY && x == endX)
		{
			isFinish = true;
			answer = (str);
		}

		return;
	}


	for (int i = 0; i < 4; ++i)
	{


		int n_x = x + dx[i];
		int n_y = y + dy[i];

		if (n_x < 0 || n_y < 0 || n_y > row - 1 || n_x > col - 1) continue;

		int distance = (abs(endX - n_x) + abs(endY - n_y));

		if ((maxDepth - (depth + 1)) - distance < 0 || ((maxDepth - (depth + 1)) - distance) % 2 == 1) continue;

		if (isFinish) continue;

		DFS(n_y, n_x, depth + 1, str + dir[i]);
	}
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
	row = n;
	col = m;
	maxDepth = k;
	endX = c - 1;
	endY = r - 1;
	int startX = y - 1;
	int startY = x - 1;

	DFS(startY, startX, 0, "");

	if (answer.empty())
	{
		return "impossible";
	}
	else
	{
		return answer;
	}
}