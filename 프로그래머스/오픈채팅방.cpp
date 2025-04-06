// https://school.programmers.co.kr/learn/courses/30/lessons/42888
// �ð� ���⵵ : O(N)

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	unordered_map<string, string> userInfo;
	for (int i = 0; i < record.size(); ++i)
	{
		string curRecord = record[i];
		stringstream ss(curRecord);
		string cmd, id, nickname;
		ss >> cmd >> id >> nickname;
		if (cmd == "Enter" || cmd == "Change")
		{
			userInfo[id] = nickname;
		}
	}

	for (int i = 0; i < record.size(); ++i)
	{
		string curRecord = record[i];
		stringstream ss(curRecord);
		string cmd, id;
		ss >> cmd >> id;
		if (cmd == "Enter")
		{
			answer.push_back(userInfo[id] + "���� ���Խ��ϴ�.");
		}
		else if (cmd == "Leave")
		{
			answer.push_back(userInfo[id] + "���� �������ϴ�.");
		}
	}

	return answer;
}