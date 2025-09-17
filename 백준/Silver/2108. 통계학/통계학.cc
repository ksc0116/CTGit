#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> numbers(N);
	vector<long long> answer;
	map<int, int> m;

	double sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
		sum += numbers[i];
		m[numbers[i]]++;
	}

	map<int, set<int>> m2;
	for (const auto& numPair : m)
	{
		int cnt = numPair.second;
		int number = numPair.first;
		m2[cnt].insert(number);
	}

	answer.push_back(round(sum / (double)N));
	sort(numbers.begin(), numbers.end());
	answer.push_back(numbers[N / 2]);
	if ((--m2.end())->second.size() == 1)
	{
		answer.push_back(*(--m2.end())->second.begin());
	}
	else
	{
		answer.push_back(*(++(--m2.end())->second.begin()));
	}
	
	long long maxVal = *max_element(numbers.begin(),numbers.end());
	long long minVal = *min_element(numbers.begin(), numbers.end());
	answer.push_back(abs(maxVal - minVal));

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}
	return 0;
}
