// https://school.programmers.co.kr/learn/courses/30/lessons/92345
// 시간 복잡도 : O(4^(M*N))

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

		// 현재 발판을 이동불가로 바꿈
		map[cy][cx] = 0;
		// 매개변수를 바꿈으로 상대방 입장의 함수 시작
		int val = DFS(opY, opX, ny, nx) + 1;
		// 다시 현재 발판을 이동가능으로 바꿈
		map[cy][cx] = 1;

		// 여태까지 지다가 이기는 경우 -> 최선을 다해야하기 때문에 갱신
		if (best % 2 == 0 && val % 2 == 1)
		{
			best = val;
		}
		// 여태까지 지다가 현재도 지는 경우 -> 최대한 오래 살아야하기 때문에 max로 비교
		else if (best % 2 == 0 && val % 2 == 0)
		{
			best = max(best, val);
		}
		// 여태까지 이기고 있다가 현재도 이기는 경우 -> 최대한 빨리 끝내야하기 때문에 min으로 비교
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