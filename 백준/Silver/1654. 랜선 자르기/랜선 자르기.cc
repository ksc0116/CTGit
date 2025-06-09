#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Check(int N, int mid, const vector<long long>& line)
{
	long long cnt = 0;

	for (int i = 0; i < line.size(); ++i)
	{
		long long curLine = line[i];
		cnt += (curLine / mid);
	}

	return cnt >= N;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;
	vector<long long> line(K);

	for (int i = 0; i < K; ++i)
	{
		cin >> line[i];
	}

	long long left = 1;
	long long right = *max_element(line.begin(), line.end());

	while (left < right)
	{
		long long mid = (left + right + 1) / 2;

		if (Check(N, mid, line))
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << left << endl;
	return 0;
}