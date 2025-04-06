// https://school.programmers.co.kr/learn/courses/30/lessons/42577
// 시간 복잡도 :O(N)

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
	bool answer = true;

	unordered_set<string> numSet;
	for (int i = 0; i < phone_book.size(); ++i)
	{
		numSet.insert(phone_book[i]);
	}
	for (int i = 0; i < phone_book.size(); ++i)
	{
		string curNumber = phone_book[i];

		for (int j = 1; j < curNumber.size(); ++j)
		{
			string slice = curNumber.substr(0, j);
			if (numSet.find(slice) != numSet.end())
			{
				return false;
			}
		}
	}

	return answer;
}