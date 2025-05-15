// https://school.programmers.co.kr/learn/courses/30/lessons/340199
// �ð� ���⵵ : O(logN)

#include <string>
#include <vector>

using namespace std;

bool Check(const vector<int>& wallet, const vector<int>& bill)
{
	int walletWidth = wallet[0];
	int walletHeight = wallet[1];
	int billWidth = bill[0];
	int billHeight = bill[1];

	if (walletWidth >= billWidth && walletHeight >= billHeight)
	{
		return true;
	}

	if (walletWidth >= billHeight && walletHeight >= billWidth)
	{
		return true;
	}

	return false;
}

void Half(vector<int>& bill)
{
	if (bill[0] > bill[1])
	{
		bill[0] /= 2;
	}
	else
	{
		bill[1] /= 2;
	}
}

int solution(vector<int> wallet, vector<int> bill)
{
	int answer = 0;


	while (true)
	{
		// ������ ���� �� �ִ��� Ȯ���ϱ�
		if (Check(wallet, bill))
		{
			break;
		}

		// ������ ����
		Half(bill);
		answer++;
	}

	return answer;
}