#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, H, T;
	cin >> N >> H >> T;

	priority_queue<int> pq;
	for (int i = 0; i < N; ++i)
	{
		int val;
		cin >> val;
		pq.push(val);
	}
	int cnt = 0;
	while (T > 0 && pq.top() >= H)
	{
		int front = pq.top();
		if (front == 1) break;
		pq.pop();
		front /= 2;
		pq.push(front);
		--T;
		cnt++;
	}

	if (pq.top() < H)
	{
		cout << "YES" << "\n";
		cout << cnt << "\n";
	}
	else
	{
		cout << "NO" << "\n";
		cout << pq.top() << "\n";
	}

	return 0;
}
