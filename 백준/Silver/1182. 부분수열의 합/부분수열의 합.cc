#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>
#include <limits.h>
using namespace std;

int answer = 0;

void DFS(const vector<int>& numbers, int targetCnt, vector<int>& curNum, int start, int S)
{
	if (targetCnt < curNum.size()) return;

	if (targetCnt == curNum.size())
	{
		int sum = 0;
		for (int i = 0; i < curNum.size(); ++i)
		{
			sum += curNum[i];
		}

		if (sum == S) answer++;
	}

	for (int i = start; i < numbers.size(); ++i)
	{
		curNum.push_back(numbers[i]);
		DFS(numbers, targetCnt, curNum, i + 1, S);
		curNum.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> numbers(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < N; ++i)
	{
		vector<int> cur;
		DFS(numbers, i + 1, cur, 0, S);
	}

	cout << answer << "\n";

	return 0;
}
