// https://school.programmers.co.kr/learn/courses/30/lessons/12973
// 시간 복잡도 : O(N)

#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> st;
	for (const auto& c : s)
	{
		char cur = c;
		if (st.empty())
		{
			st.push(cur);
		}
		else
		{
			if (st.top() == cur)
			{
				st.pop();
			}
			else
			{
				st.push(cur);
			}
		}
	}

	return st.size() == 0 ? 1 : 0;
}