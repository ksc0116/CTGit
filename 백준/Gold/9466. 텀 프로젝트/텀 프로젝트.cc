#include <iostream>
#include <vector>

using namespace std;

vector<int> students;
vector<bool> visited;
vector<bool> finished;
int teamCount;

void dfs(int cur)
{
	visited[cur] = true;
	int next = students[cur];

	if (!visited[next]) 
	{
		dfs(next);
	}
	else if (!finished[next])
	{
		for (int i = next; i != cur; i = students[i])
		{
			teamCount++;
		}
		teamCount++;
	}

	finished[cur] = true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		students = vector<int>(n);
		visited = vector<bool>(n, false);
		finished = vector<bool>(n, false);
		teamCount = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> students[i];
			students[i]--; 
		}

		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}

		cout << n - teamCount << endl; 
	}

	return 0;
}
