// https://school.programmers.co.kr/learn/courses/30/lessons/12933
// �ð� ���⵵ : O(NlogN)

#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

long long solution(long long n)
{
	string answer = to_string(n);

	sort(answer.begin(), answer.end(), greater<char>());

	return stoll(answer);
}