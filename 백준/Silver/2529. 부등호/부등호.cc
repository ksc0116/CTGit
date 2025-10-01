#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <ctype.h>
using namespace std;

string minAnswer = "9999999999";
string maxAnswer = "0000000000";

void Combi(const string& numbers, int targetCnt, string str,int start, const vector<char>& ch)
{
	if (targetCnt == str.size())
	{
		do 
		{
			bool flag = true;

			for (int i = 0; i < str.size() - 1; ++i)
			{
				char curC = ch[i];
				if (curC == '>')
				{
					if (str[i] < str[i + 1])
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (str[i] > str[i + 1])
					{
						flag = false;
						break;
					}
				}
			}

			if (flag)
			{
				minAnswer = min(minAnswer, str);
				maxAnswer = max(maxAnswer, str);
			}

		} while (next_permutation(str.begin(),str.end()));

		return;
	}

	for (int i = start; i < numbers.size(); ++i)
	{
		str.push_back(numbers[i]);
		Combi(numbers, targetCnt,str, i + 1,ch);
		str.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	vector<char> ch;
	for (int i = 0; i < k; ++i)
	{
		char c;
		cin >> c;
		ch.push_back(c);
	}

	string str = "0123456789";
	string tmp;
	Combi(str, k + 1,tmp,0,ch);

	cout << maxAnswer << "\n";
	cout << minAnswer << "\n";


	return 0;
}
