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
	
	int T;
	cin >> T;

	while (T--)
	{
		int m, n;
		cin >> m >> n;

		vector<pair<int, int>> se;

		for (int i = 0; i < m; ++i)
		{
			if (i % 2 == 0)
			{
				for (int j = 1; j < n; ++j)
				{
					se.push_back({ i,j });
				}
			}
			else
			{
				for (int j = n - 1; j >= 1; --j)
				{
					se.push_back({ i,j });
				}
			}
		}

		for (int i = m - 1; i >= 0; --i)
		{
			se.push_back({ i,0 });
		}

		cout << 1 << "\n";
		for (int i = 0; i < se.size(); ++i)
		{
			cout << "(" << se[i].first << "," << se[i].second << ")" << "\n";
		}
	}
	
	return 0;
}
