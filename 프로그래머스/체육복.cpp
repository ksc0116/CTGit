// https://school.programmers.co.kr/learn/courses/30/lessons/42862
// 시간 복잡도 : O(N)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	// cnt
	// -1 -> 없는 것
	// 0 -> 내꺼만 있는 것
	// 1 -> 여벌이 있는 것
	vector<int> cntVec(n + 2, 0);
	cntVec[0] = -1;
	cntVec[n + 1] = -1;
	// 도둑 맞은 인원 cnt 감소
	for (int i = 0; i < lost.size(); ++i)
	{
		cntVec[lost[i]]--;
	}
	// 여벌 있는 인원 cnt 증가
	for (int i = 0; i < reserve.size(); ++i)
	{
		cntVec[reserve[i]]++;
	}

	// 인원들 돌면서 현재 cnt가 -1이면 자기 자신의 앞, 뒷 사람에게 빌릴 수 있는지 검사
	for (int i = 1; i <= n; ++i)
	{
		// 앞사람 검사
		if (cntVec[i] > -1) continue;

		if (cntVec[i - 1] == 1)
		{
			cntVec[i - 1] = 0;
			cntVec[i] = 0;
			continue;
		}
		// 뒷사람 검사
		if (cntVec[i + 1] == 1)
		{
			cntVec[i + 1] = 0;
			cntVec[i] = 0;
			continue;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (cntVec[i] != -1) answer++;
	}
	return answer;
}