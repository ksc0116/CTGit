// https://school.programmers.co.kr/learn/courses/30/lessons/92345
// �ð� ���⵵ : O(4^(M*N))

#include <string>
#include <vector>

using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> map;

int DFS(int meY, int meX, int opY, int opX)
{
	if (map[meY][meX] == 0) return 0;

	int cx = meX;
	int cy = meY;

	int best = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];

		if (nx < 0 || nx >= map[0].size() || ny < 0 || ny >= map.size() || map[ny][nx] == 0) continue;

		// ���� ������ �̵��Ұ��� �ٲ�
		map[cy][cx] = 0;
		// �Ű������� �ٲ����� ���� ������ �Լ� ����
		int val = DFS(opY, opX, ny, nx) + 1;
		// �ٽ� ���� ������ �̵��������� �ٲ�
		map[cy][cx] = 1;

		// ���±��� ���ٰ� �̱�� ��� -> �ּ��� ���ؾ��ϱ� ������ ����
		if (best % 2 == 0 && val % 2 == 1)
		{
			best = val;
		}
		// ���±��� ���ٰ� ���絵 ���� ��� -> �ִ��� ���� ��ƾ��ϱ� ������ max�� ��
		else if (best % 2 == 0 && val % 2 == 0)
		{
			best = max(best, val);
		}
		// ���±��� �̱�� �ִٰ� ���絵 �̱�� ��� -> �ִ��� ���� �������ϱ� ������ min���� ��
		else if (best % 2 == 1 && val % 2 == 1)
		{
			best = min(best, val);
		}
	}

	return best;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
	map = board;

	return DFS(aloc[0], aloc[1], bloc[0], bloc[1]);
}