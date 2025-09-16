#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <limits.h>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int CheckBomb(const vector<string>& tempCandy)
{
	int maxValue = 0;

	for (int i = 0; i < tempCandy.size(); ++i)
	{
		int cnt = 1;
		char curChar = tempCandy[i][0];
		for (int j = 1; j < tempCandy[i].size(); ++j)
		{
			if (tempCandy[i][j] == curChar) cnt++;
			else
			{
				maxValue = max(maxValue, cnt);
				cnt = 1;
				curChar = tempCandy[i][j];
			}
			maxValue = max(maxValue, cnt);
		}
	}


	for (int i = 0; i < tempCandy.size(); ++i) 
	{
		int cnt = 1;
		char curChar = tempCandy[0][i];
		for (int j = 1; j < tempCandy.size(); ++j)
		{
			if (tempCandy[j][i] == curChar) cnt++;
			else
			{
				cnt = 1;
				curChar = tempCandy[j][i];
			}
			maxValue = max(maxValue, cnt);
		}
	}

	return maxValue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 0;

	int N;
	cin >> N;

	vector<string> candy(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> candy[i];
	}

	answer = max(answer, CheckBomb(candy));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char curChar = candy[i][j];
			for (int k = 0; k < 4; ++k)
			{
				int nx = dx[k] + j;
				int ny = dy[k] + i;
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (curChar == candy[ny][nx]) continue;

				vector<string> tempCandy = candy;
				tempCandy[i][j] = candy[ny][nx];
				tempCandy[ny][nx] = curChar;

				answer = max(answer, CheckBomb(tempCandy));
			}
		}
	}
	
	cout << answer << endl;

	return 0;
}
