#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char arr[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string solution(int n, int t, int m, int p)
{
	string answer = "";

	int totalCnt = m * t;

	int num = 1;
	string answerStr = "0";
	int curCnt = answerStr.size();
	while (curCnt <= m * t)
	{
		int tmpNum = num;
		string tmpStr = "";
		// 진법 변환
		while (tmpNum != 0)
		{

			tmpStr += arr[(tmpNum % n)];
			tmpNum /= n;
		}

		curCnt += tmpStr.size();
		reverse(tmpStr.begin(), tmpStr.end());
		answerStr += tmpStr;
		num++;
	}

	for (int i = 1; i <= t; ++i)
	{
		answer += answerStr[(m * (i - 1)) + (p - 1)];
	}

	return answer;
}