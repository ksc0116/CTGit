#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

vector<list<char>> info;
map<pair<int, int>, list<char>::iterator> iterMap;

void Check(int row, int col)
{
	vector<list<char>::iterator> tmpVec;
	vector<char> vec;
	auto iter = next(info[row].begin(), col);
	char curChar = *iter;
	if (curChar == '0') return;

	tmpVec.push_back(iter);
	vec.push_back(*iter);

	iter++;
	tmpVec.push_back(iter);
	vec.push_back(*iter);

	iter = next(info[row + 1].begin(), col);
	tmpVec.push_back(iter);
	vec.push_back(*iter);
	iter++;
	tmpVec.push_back(iter);
	vec.push_back(*iter);

	for (int i = 1; i < tmpVec.size(); ++i)
	{
		if (*tmpVec[i] != curChar)
		{
			return;
		}
	}

	iterMap.insert({ {row,col}, tmpVec[0] });
	iterMap.insert({ {row,col + 1}, tmpVec[1] });
	iterMap.insert({ {row + 1,col}, tmpVec[2] });
	iterMap.insert({ {row + 1,col + 1}, tmpVec[3] });
}

int solution(int m, int n, vector<string> board)
{
	int answer = 0;

	info.resize(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			info[i].push_back(board[j][i]);
		}
	}

	while (true)
	{
		iterMap.clear();

		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 0; j < m - 1; ++j)
			{
				Check(i, j);
			}
		}

		vector<vector<bool>> visit(info.size(), vector<bool>(info[0].size(), false));
		for (const auto& each : iterMap)
		{
			int row = each.first.first;
			int col = each.first.second;
			auto iter = each.second;
			if (visit[row][col]) continue;

			visit[row][col] = true;

			info[row].erase(iter);
			info[row].push_front('0');

			answer++;
		}

		if (iterMap.empty())
			break;
	}

	return answer;
}