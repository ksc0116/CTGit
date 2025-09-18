#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

long long CalSec(const vector<int>& board, int inven, int targetHeight)
{
	long long sec = 0;

	for (int i = 0; i < board.size(); ++i)
	{
		if (board[i] > targetHeight)
		{
			sec += ((board[i] - targetHeight) * 2);
			inven += (board[i] - targetHeight);
		}
		else if (board[i] < targetHeight)
		{
			if (inven >= targetHeight - board[i])
			{
				sec += targetHeight - board[i];
				inven -= targetHeight - board[i];
			}
			else
			{
				return LLONG_MAX;
			}
		}
	}

	return sec;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, B;
	cin >> N >> M >> B;

	long long minTime = LLONG_MAX;

	int maxHeight = INT_MIN;
	int minHeight = INT_MAX;

	// 시간, 높이
	map<long long, set<int>> m;
	vector<int> board;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int val = 0;
			cin >> val;
			minHeight = min(minHeight, val);
			maxHeight = max(maxHeight, val);
			board.push_back(val);
		}
	}
	sort(board.begin(), board.end(), greater<int>());
	for (int i = minHeight; i <= maxHeight; ++i)
	{
		long long sec = CalSec(board, B, i);
		m[sec].insert(i);
		minTime = min(sec, minTime);
	}

	cout << minTime << " " << *(--m[minTime].end()) << endl;

	return 0;
}
