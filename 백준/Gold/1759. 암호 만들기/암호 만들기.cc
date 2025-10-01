#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

set<string> answer;

void DFS(const vector<char>& alpha, int targetCnt, int start, string& curStr)
{
	if (targetCnt == (int)curStr.size())
	{
		int cnt = 0;
		for (int i = 0; i < curStr.size(); ++i)
		{
			if (curStr[i] == 'a' || curStr[i] == 'e' || curStr[i] == 'i' || curStr[i] == 'o' || curStr[i] == 'u')
			{
				cnt++;
			}
		}
		if(cnt >= 1 && curStr.size() - cnt >= 2)
			answer.insert(curStr);
		return;
	}

	for (int i = start; i < (int)alpha.size(); ++i)
	{
		curStr.push_back(alpha[i]);
		if (targetCnt >= curStr.size())
		{
			DFS(alpha, targetCnt, i + 1, curStr);
		}
		curStr.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, C;
	cin >> L >> C;

	vector<char> alpha(C);
	for (int i = 0; i < C; ++i)
	{
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());
	string curStr;
	DFS(alpha, L, 0, curStr);

	for (const auto& each : answer)
		cout << each << "\n";
	return 0;
}
