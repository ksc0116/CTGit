#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	cin.ignore();

	vector<string> vec(N);
	for (int i = 0; i < N; ++i)
	{
		getline(cin, vec[i]);
	}

	vector<queue<string>> bird(N);
	for (int i = 0; i < N; ++i)
	{
		stringstream ss(vec[i]);
		string word;

		while (ss >> word)
		{
			bird[i].push(word);
		}
	}

	string str;
	getline(cin, str);
	stringstream ss(str);
	string word;
	queue<string> q;
	while (ss >> word)
	{
		q.push(word);
	}

	while (!q.empty())
	{
		string targetCur = q.front();

		bool flag = false;
		for (int i = 0; i < N; ++i)
		{
			if(bird[i].empty()) continue;

			string cur = bird[i].front();
			if (cur == targetCur)
			{
				q.pop();
				bird[i].pop();
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "Impossible" << "\n";
			return 0;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (!bird[i].empty()) 
		{
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible" << "\n";
	return 0;
}
