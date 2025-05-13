// https://school.programmers.co.kr/learn/courses/30/lessons/12979
// 시간 복잡도 : O(N)

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	vector<int> empty;

	empty.push_back(stations[0] - w > 0 ? stations[0] - w - 1 : 0);
	empty.push_back(stations[stations.size() - 1] + w >= n ? 0 : n - (stations[stations.size() - 1] + w));

	for (int i = 0; i < stations.size() - 1; ++i)
	{
		int cur = stations[i] + w;
		int next = stations[i + 1] - w;
		int emptyNum = next - cur - 1;
		if (emptyNum > 0)
		{
			empty.push_back(emptyNum);
		}
	}

	for (int i = 0; i < empty.size(); ++i)
	{
		int emptyNum = empty[i];
		int length = w * 2 + 1;
		if (emptyNum % length == 0)
		{
			answer += (emptyNum / length);
		}
		else
		{
			answer += ((emptyNum / length) + 1);
		}
	}

	return answer;
}