#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isPrimeArr[10000000] = {};
unordered_set<int> numSet;

void CheckPrime()
{
	fill(isPrimeArr, isPrimeArr + 10000000, true);
	isPrimeArr[0] = false;
	isPrimeArr[1] = false;

	for (int i = 2; i < 5000000; ++i)
	{
		if (!isPrimeArr[i])
		{
			continue;
		}

		isPrimeArr[i] = true;

		for (int j = i * 2; j < 10000000; j += i)
		{
			isPrimeArr[j] = false;
		}
	}
}



int solution(string numbers)
{
	int answer = 0;

	CheckPrime();

	sort(numbers.begin(), numbers.end());

	do
	{
		string tmpStr = "";
		for (int i = 0; i < numbers.size(); ++i)
		{
			tmpStr += numbers[i];
			if (isPrimeArr[stoi(tmpStr)])
			{
				numSet.insert(stoi(tmpStr));
			}
		}

	} while (next_permutation(numbers.begin(), numbers.end()));


	return numSet.size();
}