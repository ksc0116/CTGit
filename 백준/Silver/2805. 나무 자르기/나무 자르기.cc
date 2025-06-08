#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Check(int M, int mid, const vector<int>& tree)
{
	long long sum = 0;

	for (int i = 0; i < tree.size(); ++i)
	{
		if (mid < tree[i])
		{
			sum += (tree[i] - mid);
		}
	}

	return sum >= M;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> tree(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> tree[i];
	}
	
	int left = 0;
	int right = 1000000000;

	while (left < right)
	{
		int mid = (left + right + 1) / 2;

		if (Check(M,mid, tree))
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