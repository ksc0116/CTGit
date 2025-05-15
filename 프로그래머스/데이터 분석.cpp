// https://school.programmers.co.kr/learn/courses/30/lessons/250121
// 시간 복잡도 : O(NlogN)

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<string, int> um;
vector<vector<int>> answer;
int sortIdx;

void Check(const vector<vector<int>>& data, string ext, int val_ext)
{
	int idx = um[ext];
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i][idx] < val_ext)
		{
			answer.push_back(data[i]);
		}
	}
}

bool Cmp(const vector<int>& lhs, const vector<int>& rhs)
{
	return lhs[sortIdx] < rhs[sortIdx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
	um.insert({ "code",0 });
	um.insert({ "date",1 });
	um.insert({ "maximum",2 });
	um.insert({ "remain",3 });

	sortIdx = um[sort_by];

	Check(data, ext, val_ext);

	sort(answer.begin(), answer.end(), Cmp);

	return answer;
}