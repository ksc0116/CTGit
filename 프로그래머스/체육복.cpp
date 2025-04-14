// https://school.programmers.co.kr/learn/courses/30/lessons/42862
// �ð� ���⵵ : O(N)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	// cnt
	// -1 -> ���� ��
	// 0 -> ������ �ִ� ��
	// 1 -> ������ �ִ� ��
	vector<int> cntVec(n + 2, 0);
	cntVec[0] = -1;
	cntVec[n + 1] = -1;
	// ���� ���� �ο� cnt ����
	for (int i = 0; i < lost.size(); ++i)
	{
		cntVec[lost[i]]--;
	}
	// ���� �ִ� �ο� cnt ����
	for (int i = 0; i < reserve.size(); ++i)
	{
		cntVec[reserve[i]]++;
	}

	// �ο��� ���鼭 ���� cnt�� -1�̸� �ڱ� �ڽ��� ��, �� ������� ���� �� �ִ��� �˻�
	for (int i = 1; i <= n; ++i)
	{
		// �ջ�� �˻�
		if (cntVec[i] > -1) continue;

		if (cntVec[i - 1] == 1)
		{
			cntVec[i - 1] = 0;
			cntVec[i] = 0;
			continue;
		}
		// �޻�� �˻�
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