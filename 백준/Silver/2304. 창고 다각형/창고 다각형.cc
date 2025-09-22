#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>
using namespace std;

// 시간 복잡도 : N

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> v[i].first >> v[i].second; // (x좌표, 높이)
	}

	// x 좌표 기준 정렬
	sort(v.begin(), v.end());

	// 가장 높은 기둥 찾기
	int maxH = 0, maxIdx = 0;
	for (int i = 0; i < N; i++) 
	{
		if (v[i].second > maxH) 
		{
			maxH = v[i].second;
			maxIdx = i;
		}
	}

	int area = 0;

	// 왼쪽에서 최대 기둥까지
	int curH = v[0].second;
	int curX = v[0].first;
	for (int i = 1; i <= maxIdx; i++)
	{
		if (v[i].second > curH) 
		{
			area += (v[i].first - curX) * curH;
			curH = v[i].second;
		}
		else 
		{
			area += (v[i].first - curX) * curH;
		}
		curX = v[i].first;
	}

	// 오른쪽에서 최대 기둥까지
	curH = v[N - 1].second;
	curX = v[N - 1].first;
	for (int i = N - 2; i >= maxIdx; i--)
	{
		if (v[i].second > curH) 
		{
			area += (curX - v[i].first) * curH;
			curH = v[i].second;
		}
		else 
		{
			area += (curX - v[i].first) * curH;
		}
		curX = v[i].first;
	}

	// 가장 높은 기둥 면적 추가
	area += maxH;

	cout << area << "\n";
	return 0;
}

