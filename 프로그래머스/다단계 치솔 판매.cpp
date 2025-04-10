// https://school.programmers.co.kr/learn/courses/30/lessons/77486
// 시간 복잡도 O(N * M)

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
	vector<int> answer;

	// 내 이름, 부모 이름
	unordered_map<string, string> tree;
	tree["center"] = "--";
	for (int i = 0; i < enroll.size(); ++i)
	{
		string parent = "center";
		if (referral[i] != "-") parent = referral[i];

		tree[enroll[i]] = parent;
	}
	unordered_map<string, int> profitInfo;
	for (int i = 0; i < seller.size(); ++i)
	{
		int profit = amount[i] * 100;
		string curName = seller[i];
		string parentName = tree[curName];

		while (profit * 0.1 >= 1 && parentName != "--")
		{
			int parentProfit = profit * 0.1;
			profit -= parentProfit;
			profitInfo[curName] += profit;

			profit = parentProfit;
			curName = parentName;
			parentName = tree[curName];
		}
		if (profit * 0.1 < 1)
		{
			profitInfo[curName] += profit;
		}
	}
	for (int i = 0; i < enroll.size(); ++i)
	{
		answer.push_back(profitInfo[enroll[i]]);
	}
	return answer;
}