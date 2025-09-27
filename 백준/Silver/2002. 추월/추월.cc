#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<string> p1(N);
	queue<string> p2;

	for (int i = 0; i < N; ++i)
	{
		cin >> p1[i];
	}

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		p2.push(str);
	}

	int answer = 0;
	int check = 0;
	unordered_set<string> finish;
	while (check != N)
	{
		string curCar = p1[check];
		if (finish.find(curCar) != finish.end())
		{
			check++;
			continue;
		}

		string exitCar = p2.front();
		p2.pop();
		finish.insert(exitCar);
		if (curCar != exitCar)
		{
			answer++;
		}
		else
		{
			check++;
		}
	}

	cout << answer << "\n";

	return 0;
}
