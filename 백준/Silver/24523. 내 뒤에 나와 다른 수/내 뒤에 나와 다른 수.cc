#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <limits.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	vector<int> answer(N);
	answer[N - 1] = -1;
	for (int i = N - 2; i >= 0; --i)
	{
		if (arr[i] == arr[i + 1])
		{
			answer[i] = answer[i + 1];
		}
		else
		{
			answer[i] = i + 2;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		cout << answer[i] << " ";
	}
	cout << "\n";
	return 0;
}
