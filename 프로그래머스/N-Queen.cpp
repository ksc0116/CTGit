// https://school.programmers.co.kr/learn/courses/30/lessons/12952
// 시간 복잡도 :O(N!)

#include <string>
#include <vector>
#include <cmath>

using namespace std;
long long answer = 0;
bool SameRow(int placedRow, int row)
{
	return placedRow == row;
}

bool SameDiagonal(int placedCol, int placedRow, int curCol, int curRow)
{
	return abs(placedCol - curCol) == abs(placedRow - curRow);
}

bool Check(int n, vector<int>& queens, int col, int row)
{
	for (int i = 0; i < col; ++i)
	{
		if (SameRow(queens[i], row) || SameDiagonal(i, queens[i], col, row))
		{
			return false;
		}
	}


	return true;
}

void BackTrack(int n, vector<int>& queens, int col)
{
	if (col == n) answer += 1;

	for (int i = 0; i < n; ++i)
	{
		if (Check(n, queens, col, i))
		{
			queens[col] = i;

			BackTrack(n, queens, col + 1);

			queens[col] = -1;
		}
	}
}

int solution(int n)
{
	vector<int> queens(n, -1);
	BackTrack(n, queens, 0);
	return answer;
}
