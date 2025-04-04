// https://school.programmers.co.kr/learn/courses/30/lessons/81303
// 시간 복잡도 : O(N)


#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

string solution(int n, int k, vector<string> cmd)
{
	string answer(n, 'O');

	// "U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다.
	// "D X": 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다.
	// "C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
	// "Z" : 가장 최근에 삭제된 행을 원래대로 복구합니다. 단, 현재 선택된 행은 바뀌지 않습니다.
	int last = n;
	int first = -1;

	// 이전 인덱스, 다음 인덱스
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
			// 마지막 행 삭제
			if (board[k].second == last)
			{
				board[board[k].first].second = last;
				k = board[k].first;
			}
			// 첫번째 행 삭제
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
			// 첫번째 행 추가
			if (index == 0)
			{
				board[board[index].second].first = index;
			}
			// 마지막 행 추가
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
