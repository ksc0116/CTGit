#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <cctype>

using namespace std;

void Check(const string& str, string& head, string& number)
{
	bool isChar = true;
	bool isZero = true;

	for (int i = 0; i < str.size(); ++i)
	{
		if (isChar)
		{
			if (!isdigit(str[i]))
			{
				head += string(1, str[i]);
			}

			if (i + 1 < str.size() && isdigit(str[i + 1]))
			{
				isChar = false;
			}
		}
		else
		{
			if (isZero)
			{
				if (isdigit(str[i]))
				{
					if (str[i] != '0')
					{
						isZero = false;
						number += string(1, str[i]);
					}

					if (i + 1 >= str.size() || !isdigit(str[i + 1]))
					{
						break;
					}
				}
			}
			else
			{
				number += string(1, str[i]);

				if (i + 1 >= str.size() || !isdigit(str[i + 1]))
				{
					break;
				}
			}
		}
	}
}

vector<string> solution(vector<string> files)
{
	vector<string> answer;

	unordered_map<string, string> um;

	for (int i = 0; i < files.size(); ++i)
	{
		string curStr = files[i];

		for (int j = 0; j < curStr.size(); ++j)
		{
			curStr[j] = tolower(curStr[j]);
		}

		um.insert({ files[i], curStr });
	}

	// HEAD, NUMBER
	map<pair<string, int>, vector<string>> info;

	for (int i = 0; i < files.size(); ++i)
	{
		string head = "";
		string number = "";
		Check(um[files[i]], head, number);

		if (number.empty())
		{
			number += "0";
		}

		if (info.find({ head,stoi(number) }) == info.end())
		{
			info.insert({ {head,stoi(number)} , vector<string>() });
			info[{head, stoi(number)}].push_back(files[i]);
		}
		else
		{
			info[{head, stoi(number)}].push_back(files[i]);
		}
	}

	for (const auto& each : info)
	{
		for (int i = 0; i < each.second.size(); ++i)
		{
			answer.push_back(each.second[i]);
		}
	}

	return answer;
}