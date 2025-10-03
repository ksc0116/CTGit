#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <limits.h>
using namespace std;

vector<int> answer;

bool IsPrime(int num)
{
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}

void Check(int N, int depth,int num)
{
	if (depth == N)
	{
		answer.push_back(num);
		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		int next = num * 10 + i;
		if (IsPrime(next))
		{
			Check(N, depth + 1, next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string str = "";
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			str += to_string(i);
		}
	}

	int prime[4] = { 2,3,5,7 };
	for (int i = 0; i < 4; ++i)
	{
		Check(N,1,prime[i]);
	}
	

	for (const auto& each : answer)
	{
		cout << each << "\n";
	}
	return 0;
}
