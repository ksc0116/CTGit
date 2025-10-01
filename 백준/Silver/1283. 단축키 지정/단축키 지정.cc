#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <ctype.h>
using namespace std;

bool used[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	cin.ignore(); 

	for (int i = 0; i < N; i++) 
	{
		string line;
		getline(cin, line);

		int pos = -1; 

		for (int j = 0; j < (int)line.size(); j++) 
		{
			if (j == 0 || line[j - 1] == ' ') 
			{ 
				char c = tolower(line[j]);
				if (!used[c - 'a'])
				{
					pos = j;
					break;
				}
			}
		}

		if (pos == -1)
		{
			for (int j = 0; j < (int)line.size(); j++) 
			{
				if (line[j] == ' ') continue;
				char c = tolower(line[j]);
				if (!used[c - 'a']) 
				{
					pos = j;
					break;
				}
			}
		}

		if (pos != -1)
		{
			used[tolower(line[pos]) - 'a'] = true;
			for (int j = 0; j < (int)line.size(); j++) 
			{
				if (j == pos) cout << '[' << line[j] << ']';
				else cout << line[j];
			}
		}
		else 
		{
			cout << line; 
		}
		cout << "\n";
	}

	return 0;
}
