// https://school.programmers.co.kr/learn/courses/30/lessons/12905
// 시간 복잡도 : O(N * M)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;

	for (int i = 1; i < board.size(); ++i)
	{
		for (int j = 1; j < board[0].size(); ++j)
		{
			board[i][j] = min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]) + 1;
		}
	}

	for (int i = 0; i < board.size(); ++i)
	{
		answer = max(answer, *max_element(board[i].begin(), board[i].end()));
	}

	return answer * answer;
}