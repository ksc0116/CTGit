// https://school.programmers.co.kr/learn/courses/30/lessons/12982
// 시간 복잡도 :O(N)

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget)
{
	int answer = 0;

	sort(d.begin(), d.end());
	int cnt = 0;
	for (int i = 0; i < d.size(); ++i)
	{
		if (cnt + d[i] > budget)
		{
			break;
		}
		cnt += d[i];
		answer++;
	}

	return answer;
}