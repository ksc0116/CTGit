// https://school.programmers.co.kr/learn/courses/30/lessons/60062
// 시간 복잡도 : O(M^2 * N!)

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
	int length = weak.size();
	for (int i = 0; i < length; ++i)
	{
		weak.push_back(weak[i] + n);
	}


	int answer = dist.size() + 1;


	// 모든 시작 지점을 확인하기 위해서
	for (int start = 0; start < length; ++start)
	{
		do {
			int cnt = 1;
			int position = weak[start] + dist[cnt - 1];

			// 나머지 취약지점 검사
			for (int index = start; index < start + length; ++index)
			{
				if (position < weak[index])
				{
					cnt += 1;
					if (cnt > dist.size())
					{
						break;
					}
					position = weak[index] + dist[cnt - 1];
				}
			}

			answer = min(answer, cnt);

		} while (next_permutation(dist.begin(), dist.end()));
	}

	return answer > dist.size() ? -1 : answer;
}