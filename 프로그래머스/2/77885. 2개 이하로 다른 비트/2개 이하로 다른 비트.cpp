#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
	vector<long long> answer;

	for (int i = 0; i < numbers.size(); ++i)
	{
		// 현재 수가 짝수라면 1더해서 정답에 추가
		if (numbers[i] % 2 == 0)
		{
			answer.push_back(numbers[i] + 1);
			continue;
		}

		// 현재 수가 홀수라면
		long long j = 1LL;
		while (((numbers[i] + 1) & (1LL << j)) == 0)
		{
			j++;
		}
		
		numbers[i] |= (1LL << j);
		long long tmp2 = (1LL << (j - 1));
		numbers[i] -= tmp2;
		answer.push_back(numbers[i]);
	}
	return answer;
}