#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;



bool IsSame(const string& curStr, const vector<int>& srcInfo,int srcLen)
{
	vector<int> curInfo(26);
	for (int i = 0; i < curStr.size(); ++i)
	{
		curInfo[curStr[i] - 'A']++;
	}

	int diffCnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		diffCnt += abs(curInfo[i] - srcInfo[i]);
	}

	return diffCnt <= 2 && abs((int)curStr.size() - srcLen) <= 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string src;
	cin >> src;
	vector<int> srcInfo(26);
	for (int i = 0; i < src.size(); ++i)
	{
		srcInfo[src[i] - 'A']++;
	}

	vector<string> strs;
	for (int i = 0; i < N - 1; ++i)
	{
		string str;
		cin >> str;
		strs.push_back(str);
	}

	int answer = 0;

	for (int i = 0; i < N - 1; ++i)
	{
		string curStr = strs[i];
		if (IsSame(curStr, srcInfo, src.size()))
		{
			answer++;
		}
	}

	cout << answer << "\n";
	return 0;
}

