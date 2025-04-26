// https://school.programmers.co.kr/learn/courses/30/lessons/12980
// 시간 복잡도 : O(logN)

using namespace std;

int solution(int n)
{
	int ans = 0;

	while (n != 0)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			ans++;
			n--;
		}
	}

	return ans;
}