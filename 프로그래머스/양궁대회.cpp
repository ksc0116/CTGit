// https://school.programmers.co.kr/learn/courses/30/lessons/92342
// 시간 복잡도 : (2^11)

#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int maxDiff = INT_MIN;
vector<int> tempAns;

void IsValid(const vector<int>& ryan)
{
	for (int i = 10; i >= 0; --i)
	{
		if (ryan[i] > tempAns[i])
		{
			tempAns = ryan;
			break;
		}
		else if (tempAns[i] > ryan[i])
		{
			break;
		}
	}
}

void Check(const vector<int>& info, const vector<int>& ryan)
{
	int peach = 0;
	int ryanScore = 0;
	for (int i = 0; i < ryan.size(); ++i)
	{
		if (ryan[i] != 0)
		{
			ryanScore += (10 - i);
		}
		else if (info[i] != 0)
		{
			peach += (10 - i);
		}
	}

	if (peach < ryanScore)
	{
		if (maxDiff < ryanScore - peach)
		{
			maxDiff = ryanScore - peach;
			tempAns = ryan;
		}
		else if (maxDiff == ryanScore - peach)
		{
			IsValid(ryan);
		}
	}
}

void DFS(const vector<int>& info, vector<int> ryan, int arrowCnt, int depth)
{
	if (depth == info.size() || arrowCnt == 0)
	{
		ryan[10] += arrowCnt;
		Check(info, ryan);
		ryan[10] = 0;
		return;
	}

	// 라이언이 점수를 얻는 경우
	if (arrowCnt > info[depth])
	{
		ryan[depth] = info[depth] + 1;
		DFS(info, ryan, arrowCnt - (info[depth] + 1), depth + 1);
		ryan[depth] = 0;
	}

	// 라이언이 점수를 얻지 않는 경우
	DFS(info, ryan, arrowCnt, depth + 1);
}

vector<int> solution(int n, vector<int> info)
{
	vector<int> answer;
	vector<int> ryan(11, 0);
	tempAns.resize(11, 0);
	DFS(info, ryan, n, 0);

	return maxDiff < 0 ? vector<int>(1, -1) : tempAns;
}