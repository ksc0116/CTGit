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

	vector<vector<int>> arr(N);
	vector<vector<int>> dp(N);
	for (int i = 0; i < N; ++i)
	{
		arr[i].resize(i + 1);
		dp[i].resize(i + 1);
		for (int j = 0; j < i + 1; ++j)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		dp[N - 1][i] = arr[N - 1][i];
	}

	for (int i = N - 2; i >= 0; --i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			dp[i][j] = max(dp[i + 1][j] + arr[i][j], dp[i + 1][j + 1] + arr[i][j]);
		}
	}
	
	cout << dp[0][0] << "\n";
	
	return 0;
}
