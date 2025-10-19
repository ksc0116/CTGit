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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		vector<string> info(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> info[i];
		}

		sort(info.begin(), info.end());
		bool flag = false;
		for (int i = 0; i < n - 1; ++i) 
		{
			if (info[i + 1].rfind(info[i], 0) == 0)
			{ 
				flag = true;
				break;
			}
		}

		cout << (flag ? "NO\n" : "YES\n");
	}

	return 0;
}
