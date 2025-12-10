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
	
	int N, K;
	cin >> N >> K;

	vector<int> dp(K + 1, 0);

	for (int i = 0; i < N; i++) 
	{
		int W, V;
		cin >> W >> V;

		for (int j = K; j >= W; j--)
		{
			dp[j] = max(dp[j], dp[j - W] + V);
		}
	}

	cout << dp[K];
	
	return 0;
}
