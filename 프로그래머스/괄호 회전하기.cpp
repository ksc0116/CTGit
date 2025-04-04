// https://school.programmers.co.kr/learn/courses/30/lessons/76502
// 시간 복잡도 : O(N^2)

#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool Check(queue<char> q)
{
	stack<char> st;

	while (!q.empty())
	{
		char c = q.front();
		if (c == '(' || c == '{' || c == '[')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			if (st.empty()) return false;
			if (st.top() != '(') return false;
			st.pop();
		}
		else if (c == '}')
		{
			if (st.empty()) return false;
			if (st.top() != '{') return false;
			st.pop();
		}
		else
		{
			if (st.empty()) return false;
			if (st.top() != '[') return false;
			st.pop();
		}
		q.pop();
	}

	if (st.empty()) return true;
	else return false;
}

int solution(string s)
{
	int answer = 0;

	queue<char> q;
	for (const auto& c : s)
	{
		q.push(c);
	}

	for (int i = 0; i < q.size(); ++i)
	{
		if (Check(q))
		{
			answer++;
		}
		char front = q.front();
		q.pop();
		q.push(front);
	}

	return answer;
}