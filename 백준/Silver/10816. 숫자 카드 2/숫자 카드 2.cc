#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> answer;
vector<int> findList;
vector<int> myList;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M = 0;
	cin >> M;
	findList.resize(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> findList[i];
	}
	sort(findList.begin(), findList.end());

	int N = 0;
	cin >> N;
	myList.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> myList[i];
	}

	for (int i = 0; i < myList.size(); ++i)
	{
		int target = myList[i];

		auto first = lower_bound(findList.begin(), findList.end(),target);
		auto end = upper_bound(findList.begin(), findList.end(),target);

		answer.push_back((end - first));
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}