#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>
#include <limits.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	int strIdx = 0;
	
	for (int i = 1; ; i++)
	{
		string num = to_string(i);
		for (char c : num) 
		{
			if (str[strIdx] == c) 
			{
				strIdx++;
				if (strIdx == str.size())
				{
					cout << i << "\n";
					return 0;
				}
			}
		}
	}

	return 0;
}
