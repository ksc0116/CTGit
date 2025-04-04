// https://school.programmers.co.kr/learn/courses/30/lessons/64061
// 시간 복잡도 : O(N^2 + M)

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	// 0 0 0 0 0
	// 0 0 1 0 3
	// 0 2 5 0 1
	// 4 2 4 4 2
	// 3 5 1 3 1

	// 1 5 3 5 1 2 1 4

	vector<stack<int>> boardSt(board.size());
	stack<int> basket;

	for (int i = 0; i < board[0].size(); ++i)
	{
		for (int j = board.size() - 1; j >= 0; --j)
		{
			if (board[j][i] == 0) continue;
			boardSt[i].push(board[j][i]);
		}
	}

	for (int i = 0; i < moves.size(); ++i)
	{
		int curMove = moves[i] - 1;
		if (boardSt[curMove].empty()) continue;
		if (basket.empty())
		{
			basket.push(boardSt[curMove].top());
			boardSt[curMove].pop();
			continue;
		}

		if (basket.top() == boardSt[curMove].top())
		{
			answer += 2;
			basket.pop();
		}
		else
		{
			basket.push(boardSt[curMove].top());
		}
		boardSt[curMove].pop();
	}

	return answer;
}