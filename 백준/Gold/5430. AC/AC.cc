#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> answer;

	int T;
	cin >> T;
	while (T--)
	{
		string strf;
		cin >> strf;

		int cnt;
		cin >> cnt;

		string stra;
		cin >> stra;

		deque<int> dq;
		string num = "";

		for (int i = 0; i < stra.size(); ++i)
		{
			if (isdigit(stra[i]))
			{
				num += stra[i];
			}
			else if (!num.empty())
			{
				dq.push_back(stoi(num));
				num.clear();
			}
		}

		bool isError = false;
		bool isReversed = false;

		for (char c : strf)
		{
			if (c == 'R')
			{
				isReversed = !isReversed;
			}
			else
			{
				if (dq.empty())
				{
					answer.push_back("error");
					isError = true;
					break;
				}
				if (isReversed)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}

		if (!isError)
		{
			string res = "[";
			if (isReversed)
			{
				for (auto it = dq.rbegin(); it != dq.rend(); ++it)
				{
					res += to_string(*it);
					if (it + 1 != dq.rend())
						res += ",";
				}
			}
			else
			{
				for (auto it = dq.begin(); it != dq.end(); ++it)
				{
					res += to_string(*it);
					if (it + 1 != dq.end())
						res += ",";
				}
			}
			res += "]";
			answer.push_back(res);
		}
	}

	for (const string& res : answer)
	{
		cout << res << "\n";
	}

	return 0;
}
