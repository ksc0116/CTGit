#include <string>
#include <vector>

using namespace std;

void Recur(int row, int col, int length, const vector<vector<int>>& arr, vector<int>& answer)
{
	int curNum = arr[row][col];

	if (length == 1)
	{
		answer[curNum]++;
		return;
	}


	bool flag = true;

	for (int i = row; i < row + length; ++i)
	{
		for (int j = col; j < col + length; ++j)
		{
			if (curNum != arr[i][j])
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}

	if (!flag)
	{
		Recur(row, col, length / 2, arr, answer);
		Recur(row, col + (length / 2), length / 2, arr, answer);
		Recur(row + (length / 2), col, length / 2, arr, answer);
		Recur(row + (length / 2), col + (length / 2), length / 2, arr, answer);
	}
	else
	{
		answer[curNum]++;
	}
}

vector<int> solution(vector<vector<int>> arr)
{
	vector<int> answer(2, 0);

	Recur(0, 0, arr.size(), arr, answer);

	return answer;
}