// https://school.programmers.co.kr/learn/courses/30/lessons/120861
// 시간 복잡도 : O(N)

#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<string> keyinput, vector<int> board)
{
	vector<int> answer(2, 0);

	for (int i = 0; i < keyinput.size(); ++i)
	{
		int cx = answer[0];
		int cy = answer[1];
		string curCommand = keyinput[i];
		if (curCommand == "left" && cx - 1 >= -board[0] / 2)
		{
			answer[0]--;
		}
		else if (curCommand == "right" && cx + 1 <= board[0] / 2)
		{
			answer[0]++;
		}
		else if (curCommand == "up" && cy + 1 <= board[1] / 2)
		{
			answer[1]++;
		}
		else if (curCommand == "down" && cy - 1 >= -board[1] / 2)
		{
			answer[1]--;
		}
	}

	return answer;
}