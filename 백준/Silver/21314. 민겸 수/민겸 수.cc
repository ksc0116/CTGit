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

	string s;
	cin >> s;

	string maxAns = "", minAns = "";
	int mCnt = 0;

	// 최대값 구성
	for (char c : s) 
	{
		if (c == 'M') 
		{
			mCnt++;
		}
		else
		{ // 'K'
			// K 나오면 최대: 5 뒤에 mCnt 개의 0
			maxAns.push_back('5');
			for (int i = 0; i < mCnt; ++i) maxAns.push_back('0');
			mCnt = 0;
		}
	}
	// 남은 M들은 모두 '1'로 채움 (최대)
	for (int i = 0; i < mCnt; ++i) maxAns.push_back('1');

	// 최소값 구성
	mCnt = 0;
	for (char c : s) 
	{
		if (c == 'M')
		{
			mCnt++;
		}
		else 
		{ // 'K'
			if (mCnt > 0)
			{
				// M이 mCnt개 있으면: '1' + (mCnt-1)*'0' + '5'
				minAns.push_back('1');
				for (int i = 0; i < mCnt - 1; ++i) minAns.push_back('0');
				minAns.push_back('5');
			}
			else
			{
				// 바로 K이면 그냥 5
				minAns.push_back('5');
			}
			mCnt = 0;
		}
	}
	// 끝에 M들만 남았을 때: '1' + (mCnt-1)*'0'
	if (mCnt > 0)
	{
		minAns.push_back('1');
		for (int i = 0; i < mCnt - 1; ++i) minAns.push_back('0');
	}

	cout << maxAns << "\n" << minAns << "\n";
	return 0;
}
