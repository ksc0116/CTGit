#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

constexpr int RIGHT = 1;
constexpr int LEFT = 2;
constexpr int DOWN = 3;
constexpr int UP = 4;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K;
	cin >> K;

	int vMax = INT_MIN;
	int hMax = INT_MIN;

	vector<pair<int, int>> edge;

	for (int i = 0; i < 6; ++i)
	{
		int dir = 0;
		int length = 0;
		cin >> dir >> length;
		edge.push_back({ dir,length });

		if (dir == UP || dir == DOWN)
		{
			vMax = max(vMax, length);
		}
		else
		{
			hMax = max(hMax, length);
		}
	}

	int vMin = 0;
	int hMin = 0;

	for (int i = 0; i < 6; ++i)
	{
		int dir = edge[i].first;
		int length = edge[i].second;
		if ((dir == DOWN || dir == UP) && length == vMax)
		{
			hMin = abs(edge[(i + 1) % 6].second - edge[(i + 5) % 6].second);
		}
		else if((dir == LEFT || dir == RIGHT) && length == hMax)
		{
			vMin = abs(edge[(i + 1) % 6].second - edge[(i + 5) % 6].second);
		}
	}


	cout << ((vMax * hMax) - (vMin*hMin)) * K << endl;

	return 0;
}
