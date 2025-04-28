// https://school.programmers.co.kr/learn/courses/30/lessons/12945
// 시간 복잡도 : O(N)

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	vector<int> fibo = { 0,1 };

	for (int i = 2; i <= n; ++i)
	{
		fibo.push_back((fibo[i - 1] + fibo[i - 2]) % 1234567);
	}

	return fibo[n];
}