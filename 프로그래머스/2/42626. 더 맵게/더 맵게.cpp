#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
	int answer = 0;

	priority_queue<long long> pq;

	for (int i = 0; i < scoville.size(); ++i)
	{
		pq.push(-scoville[i]);
	}

	while (pq.size() > 1 && -pq.top() < K)
	{
		answer++;
		long long curScov = -pq.top();
		pq.pop();
		long long nextScov = -pq.top();
		pq.pop();
		long long newScov = curScov + (nextScov * 2);
		pq.push(-newScov);
	}

	if (-pq.top() < K)
		return -1;

	return answer;
}