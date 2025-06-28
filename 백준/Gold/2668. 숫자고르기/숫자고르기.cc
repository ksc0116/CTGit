#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <limits.h>

using namespace std;
vector<bool> visit;
vector<bool> done;
vector<int> nums;
set<int> answer;

void DFS(int cur)
{
	visit[cur] = true;
	int next = nums[cur];
	if (!visit[next])
	{
		DFS(next);
	}
	else if(!done[next])
	{
		for (int i = next; i != cur; i = nums[i])
		{
			answer.insert(i);
		}
		answer.insert(cur);
	}

	done[cur] = true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	nums.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
		nums[i]--;
	}

	
	visit.resize(N);
	done.resize(N);

	for (int i = 0; i < N; ++i)
	{
		if (!visit[i])
			DFS(i);
	}

	cout << answer.size() << endl;
	for (auto each : answer)
	{
		cout << ++each << endl;
	}

	return 0;
}
