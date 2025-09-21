#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

bool Check(const vector<int>& info, const vector<int>& peoples)
{
	if (info[peoples[0]] != 0) return false;


	for (int i = 1; i < peoples.size(); ++i)
	{
		int left = info[peoples[i]];
		int curPeople = peoples[i];
		int cnt = 0;
		for (int j = 0; j < i; ++j)
		{
			if (curPeople < peoples[j])
			{
				cnt++;
			}
		}
		if (cnt != left)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;

	vector<int> info(N);
	vector<int> peoples(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> info[i];
		peoples[i] = i;
	}

	do 
	{
		if (Check(info, peoples))
		{
			break;
		}

	} while (next_permutation(peoples.begin(), peoples.end()));

	for (int i = 0; i < N; ++i)
	{
		cout << peoples[i] + 1 << " ";
	}

	return 0;
}
