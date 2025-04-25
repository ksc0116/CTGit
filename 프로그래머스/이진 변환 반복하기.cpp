// https://school.programmers.co.kr/learn/courses/30/lessons/70129
// 시간 복잡도 : O(NlogN)

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
	vector<int> answer(2, 0);

	int cnt = 0;

	while (s.size() != 1)
	{
		cnt++;
		answer[1] += count(s.begin(), s.end(), '0');
		s.erase(remove_if(s.begin(), s.end(), [](char ch) {return ch == '0'; }), s.end());

		int size = s.size();

		stack<int> st;
		while (size != 0)
		{
			st.push(size % 2);
			size /= 2;
		}

		s.clear();
		while (!st.empty())
		{
			s += to_string(st.top());
			st.pop();
		}
	}
	answer[0] = cnt;
	return answer;
}