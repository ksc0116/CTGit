// https://school.programmers.co.kr/learn/courses/30/lessons/81303
// �ð� ���⵵ : O(N)


#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

string solution(int n, int k, vector<string> cmd)
{
	string answer(n, 'O');

	// "U X": ���� ���õ� �࿡�� Xĭ ���� �ִ� ���� �����մϴ�.
	// "D X": ���� ���õ� �࿡�� Xĭ �Ʒ��� �ִ� ���� �����մϴ�.
	// "C" : ���� ���õ� ���� ������ ��, �ٷ� �Ʒ� ���� �����մϴ�. ��, ������ ���� ���� ������ ���� ��� �ٷ� �� ���� �����մϴ�.
	// "Z" : ���� �ֱٿ� ������ ���� ������� �����մϴ�. ��, ���� ���õ� ���� �ٲ��� �ʽ��ϴ�.
	int last = n;
	int first = -1;

	// ���� �ε���, ���� �ε���
	vector<pair<int, int>> board;
	stack<int> st;
	for (int i = 0; i < n; ++i)
	{
		board.push_back({ i - 1, i + 1 });
	}

	for (int i = 0; i < cmd.size(); ++i)
	{
		string curCmd = cmd[i];

		if (curCmd[0] == 'C')
		{
			st.push(k);
			// ������ �� ����
			if (board[k].second == last)
			{
				board[board[k].first].second = last;
				k = board[k].first;
			}
			// ù��° �� ����
			else if (board[k].first == first)
			{
				board[board[k].second].first = first;
				k = board[k].second;
			}
			else
			{
				board[board[k].first].second = board[k].second;
				board[board[k].second].first = board[k].first;
				k = board[k].second;
			}
		}
		else if (curCmd[0] == 'Z')
		{
			int index = st.top();
			st.pop();
			// ù��° �� �߰�
			if (index == 0)
			{
				board[board[index].second].first = index;
			}
			// ������ �� �߰�
			else if (index == n - 1)
			{
				board[board[index].first].second = index;
			}
			else
			{
				board[board[index].first < 0 ? 0 : board[index].first].second = index;
				board[board[index].second > n - 1 ? n - 1 : board[index].second].first = index;
			}
		}
		else
		{
			int offset = stoi(curCmd.substr(2));

			if (curCmd[0] == 'U')
			{
				for (int i = 0; i < offset; ++i)
				{
					if (board[k].first < 0) continue;
					k = board[k].first;
				}
			}
			else
			{
				for (int i = 0; i < offset; ++i)
				{
					if (board[k].second > n - 1) continue;
					k = board[k].second;
				}
			}
		}
	}

	while (!st.empty())
	{
		answer[st.top()] = 'X';
		st.pop();
	}

	return answer;
}
// n -> 5
// -1 1     0
//  0 3     1
//  1 3     2
//  1 4     3
//  3 5     4
