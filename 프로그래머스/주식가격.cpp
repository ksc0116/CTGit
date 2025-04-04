// https://school.programmers.co.kr/learn/courses/30/lessons/42584
// 시간 복잡도 : O(N)

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer(prices.size());

	stack<int> st;

	for (int i = 0; i < prices.size(); ++i)
	{
		int curPrice = prices[i];

		while (!st.empty() && prices[st.top()] > curPrice)
		{
			answer[st.top()] = i - st.top();
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty())
	{
		answer[st.top()] = prices.size() - 1 - st.top();
		st.pop();
	}

	return answer;
}