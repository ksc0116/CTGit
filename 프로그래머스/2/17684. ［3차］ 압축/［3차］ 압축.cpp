#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
	vector<int> answer;

	// 초기에 사전 만들기
	unordered_map<string, int> um;
	char tmpChar = 'A';
	for (int i = 0; i < 26; ++i)
	{
		um.insert({ string(1, tmpChar + i), i + 1 });
	}

	int curIdx = 0;
	while (curIdx < msg.size())
	{
		
		string curStr = string(1,msg[curIdx]);

		while (true)
		{
			auto iter = um.find(curStr);
			if (iter != um.end())
			{
				curIdx++;
				curStr += msg[curIdx];
			}
			else
			{
				answer.push_back(um[curStr.substr(0, curStr.size() - 1)]);
				um.insert({ string(curStr), um.size() + 1 });
				break;
			}
		}
	}

	return answer;
}