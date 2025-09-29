#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>
#include <limits.h>
using namespace std;

// 시간 복잡도 : 2^N * N!

int answer = INT_MAX;

int calcTeamScore(const vector<vector<int>>& board, const vector<int>& curTeam) 
{
	int teamScore = 0;
	for (int i = 0; i < curTeam.size(); ++i) 
	{
		for (int j = i + 1; j < curTeam.size(); ++j) 
		{
			int p1 = curTeam[i];
			int p2 = curTeam[j];
			teamScore += board[p1][p2] + board[p2][p1];
		}
	}
	return teamScore;
}

void makeTeam(const vector<vector<int>>& board, int N, int start, vector<int>& curTeam)
{
	if (curTeam.size() == N / 2) 
	{
		int teamAScore = calcTeamScore(board, curTeam);
		int teamBScore = 0;
		vector<bool> isInA(N, false);
		for (int idx : curTeam)
		{
			isInA[idx] = true;
		}
		vector<int> teamB;
		for (int i = 0; i < N; ++i)
		{
			if (!isInA[i])
			{
				teamB.push_back(i);
			}
		}
		teamBScore = calcTeamScore(board, teamB);

		int diff = abs(teamAScore - teamBScore);
		answer = min(answer, diff);
		return;
	}

	for (int i = start; i < N; ++i)
	{
		curTeam.push_back(i);
		makeTeam(board, N, i + 1, curTeam);
		curTeam.pop_back();
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	vector<int> curTeam;
	makeTeam(board, N, 0, curTeam);

	cout << answer << "\n";
	return 0;
}
